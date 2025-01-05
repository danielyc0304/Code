"use client";

import CustomButton from "../forms/CustomButton";
import Modal from "./Modal";

import useLoginModal from "@/app/hooks/useLoginModal";

const LoginModal = () => {
  const loginModal = useLoginModal();

  const content = (
    <>
      <form className="space-y-4">
        <input
          placeholder="Your e-mail address"
          type="email"
          className="h-[54px] w-full rounded-xl border border-gray-300 px-4"
        />

        <input
          placeholder="Your password"
          type="password"
          className="h-[54px] w-full rounded-xl border border-gray-300 px-4"
        />

        <div className="bg-airbnb rounded-xl p-5 text-white opacity-80">
          The error message
        </div>

        <CustomButton label="Submit" onClick={() => console.log("Test")} />
      </form>
    </>
  );

  return (
    <Modal
      isOpen={loginModal.isOpen}
      close={loginModal.close}
      label="Log in"
      content={content}
    />
  );
};

export default LoginModal;
