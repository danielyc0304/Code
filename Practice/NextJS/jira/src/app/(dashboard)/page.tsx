import { redirect } from "next/navigation";

import { CreateWorkspaceForm } from "@/features/workspaces/components/create-workspace-form";

import { getCurrent } from "@/features/auth/actions";

export default async function Home() {
  const user = await getCurrent();

  if (!user) {
    redirect("/sign-in");
  }

  return (
    <div className="h-full bg-neutral-500 p-4">
      <CreateWorkspaceForm />
    </div>
  );
}
