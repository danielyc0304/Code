"use client";

import { useRouter } from "next/navigation";

import useLoginModal from "../hooks/useLoginModal";

import apiService from "../services/apiService";

interface ContactButtonProps {
  userId: string | null;
  landlordId: string;
}

const ContactButton: React.FC<ContactButtonProps> = ({
  userId,
  landlordId,
}) => {
  const router = useRouter();
  const loginModal = useLoginModal();

  const startConvresation = async () => {
    if (userId) {
      const conversation = await apiService.get(
        `/api/chat/start/${landlordId}`,
      );

      if (conversation.conversation_id) {
        router.push(`/inbox/${conversation.conversation_id}`);
      }
    } else {
      loginModal.open();
    }
  };

  return (
    <div
      onClick={startConvresation}
      className="mt-6 cursor-pointer rounded-xl bg-airbnb px-6 py-4 text-white transition hover:bg-airbnb-dark"
    >
      Contact
    </div>
  );
};

export default ContactButton;
