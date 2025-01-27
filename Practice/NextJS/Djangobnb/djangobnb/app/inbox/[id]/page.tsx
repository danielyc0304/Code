import { UserType } from "../page";
import ConversationDetail from "@/app/components/inbox/ConversationDetail";

import apiService from "@/app/services/apiService";
import { getAccessToken, getUserId } from "@/app/lib/actions";

export type MessageType = {
  id: string;
  name: string;
  body: string;
  conversationId: string;
  sent_to: UserType;
  created_by: UserType;
};

const ConversationPage = async ({ params }: { params: { id: string } }) => {
  const token = await getAccessToken();
  const userId = await getUserId();

  if (!userId || !token) {
    return (
      <main className="max-auto max-w-[1500px] px-6 py-12">
        <p>You need to be authenticated...</p>
      </main>
    );
  }

  const conversation = await apiService.get(`/api/chat/${params.id}/`);

  return (
    <main className="mx-auto max-w-[1500px] px-6 pb-6">
      <ConversationDetail
        token={token}
        userId={userId}
        messages={conversation.messages}
        conversation={conversation.conversation}
      />
    </main>
  );
};

export default ConversationPage;
