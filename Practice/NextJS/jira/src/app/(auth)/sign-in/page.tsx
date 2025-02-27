import { redirect } from "next/navigation";

import { SignInCard } from "@/features/auth/components/sign-in-card";

import { getCurrent } from "@/features/auth/actions";

const SignInPage = async () => {
  const user = await getCurrent();

  console.log({ user });

  if (user) {
    redirect("/");
  }

  return <SignInCard />;
};

export default SignInPage;
