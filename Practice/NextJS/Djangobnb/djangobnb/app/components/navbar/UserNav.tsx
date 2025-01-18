"use client";

import { useState } from "react";
import { useRouter } from "next/navigation";

import LogoutButton from "../LogoutButton";
import MenuLink from "./MenuLink";

import useLoginModal from "@/app/hooks/useLoginModal";
import useSignupModal from "@/app/hooks/useSignupModal";

interface UserNavProps {
  userId?: string | null;
}

const UserNav: React.FC<UserNavProps> = ({ userId }) => {
  const [isOpen, setIsOpen] = useState(false);
  const router = useRouter();
  const loginModal = useLoginModal();
  const signupModal = useSignupModal();

  console.log("asdf", userId);

  return (
    <div className="relative inline-block rounded-full border p-2">
      <button onClick={() => setIsOpen(!isOpen)} className="flex items-center">
        <svg
          fill="none"
          viewBox="0 0 24 24"
          strokeWidth="1.5"
          stroke="currentColor"
          className="h-6 w-6"
        >
          <path
            strokeLinecap="round"
            strokeLinejoin="round"
            d="M3.75 6.75h16.5M3.75 12h16.5m-16.5 5.25h16.5"
          />
        </svg>

        <svg
          fill="none"
          viewBox="0 0 24 24"
          strokeWidth="1.5"
          stroke="currentColor"
          className="h-6 w-6"
        >
          <path
            strokeLinecap="round"
            strokeLinejoin="round"
            d="M15.75 6a3.75 3.75 0 1 1-7.5 0 3.75 3.75 0 0 1 7.5 0ZM4.501 20.118a7.5 7.5 0 0 1 14.998 0A17.933 17.933 0 0 1 12 21.75c-2.676 0-5.216-.584-7.499-1.632Z"
          />
        </svg>
      </button>

      {isOpen && (
        <div className="absolute right-0 top-[60px] flex w-[220px] cursor-pointer flex-col rounded-xl border bg-white shadow-md">
          {userId ? (
            <>
              <MenuLink
                label="My properties"
                onClick={() => {
                  setIsOpen(false);
                  router.push("/myproperties");
                }}
              />

              <MenuLink
                label="My reservations"
                onClick={() => {
                  setIsOpen(false);
                  router.push("/myreservations");
                }}
              />

              <LogoutButton />
            </>
          ) : (
            <>
              <MenuLink
                label="Log in"
                onClick={() => {
                  setIsOpen(false);
                  loginModal.open();
                }}
              />

              <MenuLink
                label="Sign up"
                onClick={() => {
                  setIsOpen(false);
                  signupModal.open();
                }}
              />
            </>
          )}
        </div>
      )}
    </div>
  );
};

export default UserNav;
