import { Editor } from "./editor";
import { Navbar } from "./navbar";
import { Toolbar } from "./toolbar";

interface DocumentIdPageProps {
  params: Promise<{ documentId: string }>;
}

const DocumentIdPage = async ({ params }: DocumentIdPageProps) => {
  return (
    <div className="min-h-screen bg-[#fafbfd]">
      <div className="fixed top-0 right-0 left-0 z-10 flex flex-col gap-y-2 bg-[#fafbfd] px-4 pt-2 print:hidden">
        <Navbar />

        <Toolbar />
      </div>

      <div className="pt-[114px] print:pt-0">
        <Editor />
      </div>
    </div>
  );
};

export default DocumentIdPage;
