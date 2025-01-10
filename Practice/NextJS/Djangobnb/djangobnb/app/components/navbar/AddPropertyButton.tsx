"use client";

import useAddPropertyModal from "@/app/hooks/useAddPropertyModal";
import useLoginModal from "@/app/hooks/useLoginModal";

interface AddPropertyButtonProps {
  userId?: string | null;
}

const AddPropertyButton: React.FC<AddPropertyButtonProps> = ({ userId }) => {
  const addPropertyModal = useAddPropertyModal();
  const loginModal = useLoginModal();

  const airbnbYourHome = () => {
    if (userId) {
      addPropertyModal.open();
    } else {
      loginModal.open();
    }
  };

  return (
    <div
      onClick={airbnbYourHome}
      className="cursor-pointer rounded-full p-2 text-sm font-semibold hover:bg-gray-200"
    >
      Djangobnb your home
    </div>
  );
};

export default AddPropertyButton;
