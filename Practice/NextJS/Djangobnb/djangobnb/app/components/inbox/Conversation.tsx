"use client";

import { useRouter } from "next/navigation";

import { ConversationType } from "@/app/inbox/page";

interface ConversationProps {
  conversation: ConversationType;
  userId: string;
}

const Conversation: React.FC<ConversationProps> = ({
  conversation,
  userId,
}) => {
  const router = useRouter();

  const otherUser = conversation.users.find((user) => user.id != userId);

  return (
    <div className="cursor-pointer rounded-xl border border-gray-300 px-6 py-4">
      <p className="mb-6 text-xl">{otherUser?.name}</p>

      <p
        onClick={() => router.push(`/inbox/${conversation.id}`)}
        className="text-airbnb-dark"
      >
        Go to conversation
      </p>
    </div>
  );
};

export default Conversation;
