"use client";

import { useEffect, useRef, useState } from "react";
import useWebSocket from "react-use-websocket";

import { ConversationType, UserType } from "@/app/inbox/page";
import { MessageType } from "@/app/inbox/[id]/page";
import CustomButton from "../forms/CustomButton";

interface ConversationDetailProps {
  token: string;
  userId: string;
  conversation: ConversationType;
  messages: MessageType[];
}

const ConversationDetail: React.FC<ConversationDetailProps> = ({
  userId,
  token,
  messages,
  conversation,
}) => {
  const [newMessage, setNewMessage] = useState("");
  const [realtimeMessages, setRealtimeMessages] = useState<MessageType[]>([]);
  const messagesDiv = useRef(null);
  const { sendJsonMessage, lastJsonMessage, readyState } = useWebSocket(
    `ws://127.0.0.1:8000/ws/${conversation.id}/?token=${token}`,
    { share: false, shouldReconnect: () => true },
  );

  const myUser = conversation.users?.find((user) => user.id == userId);
  const otherUser = conversation.users?.find((user) => user.id != userId);

  const scrollToBottom = () => {
    if (messagesDiv.current) {
      messagesDiv.current.scrollTop = messagesDiv.current.scrollheight;
    }
  };

  const sendMessage = async () => {
    console.log("sendMessage");

    sendJsonMessage({
      event: "chat_message",
      data: {
        body: newMessage,
        name: myUser?.name,
        sent_to_id: otherUser?.id,
        conversation_id: conversation.id,
      },
    });

    setNewMessage("");

    setTimeout(() => {
      scrollToBottom();
    }, 50);
  };

  useEffect(() => {
    if (
      lastJsonMessage &&
      typeof lastJsonMessage === "object" &&
      "name" in lastJsonMessage &&
      "body" in lastJsonMessage
    ) {
      const message: MessageType = {
        id: "",
        name: lastJsonMessage.name as string,
        body: lastJsonMessage.body as string,
        sent_to: otherUser as UserType,
        created_by: myUser as UserType,
        conversationId: conversation.id,
      };

      setRealtimeMessages((realtimeMessages) => [...realtimeMessages, message]);
    }

    scrollToBottom();
  }, [lastJsonMessage]);

  useEffect(() => {
    console.log("Connection state changed", readyState);
  }, [readyState]);

  return (
    <>
      <div
        ref={messagesDiv}
        className="flex max-h-[400px] flex-col space-y-4 overflow-auto"
      >
        {messages.map((message, index) => (
          <div
            key={index}
            className={`w-[80%]py-4 rounded-xl px-6 ${message.created_by.name == myUser?.name ? "ml-[20%] bg-blue-200" : "bg-gray-200"}`}
          >
            <p className="font-bold text-gray-500">{message.created_by.name}</p>
            <p>{message.body}</p>
          </div>
        ))}

        {realtimeMessages.map((message, index) => (
          <div
            key={index}
            className={`w-[80%]py-4 rounded-xl px-6 ${message.name == myUser?.name ? "ml-[20%] bg-blue-200" : "bg-gray-200"}`}
          >
            <p className="font-bold text-gray-500">{message.name}</p>
            <p>{message.body}</p>
          </div>
        ))}
      </div>

      <div className="mt-4 flex space-x-4 rounded-xl border border-gray-300 px-6 py-4">
        <input
          type="text"
          placeholder="Type your message..."
          className="w-full rounded-xl bg-gray-200 p-2"
          value={newMessage}
          onChange={(e) => setNewMessage(e.target.value)}
        />

        <CustomButton
          label="Send"
          onClick={sendMessage}
          className="w-[100px]"
        />
      </div>
    </>
  );
};

export default ConversationDetail;
