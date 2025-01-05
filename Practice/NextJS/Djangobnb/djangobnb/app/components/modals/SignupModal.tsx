"use client";

import CustomButton from "../forms/CustomButton";
import Modal from "./Modal";

import useSignupModal from "@/app/hooks/useSignupModal";

const SignupModal = () => {
  const signupModal = useSignupModal();

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

        <input
          placeholder="Repeat password"
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
      isOpen={signupModal.isOpen}
      close={signupModal.close}
      label="Sign up"
      content={content}
    />
  );
};

export default SignupModal;
