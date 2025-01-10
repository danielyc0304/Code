import Image from "next/image";
import Link from "next/link";

import SearchFilters from "./SearchFilters";
import AddPropertyButton from "./AddPropertyButton";
import UserNav from "./UserNav";

import { getUserId } from "@/app/lib/actions";

const Navbar = async () => {
  const userId = await getUserId();

  console.log("userid:", userId);

  return (
    <nav className="fixed left-0 top-0 z-10 w-full border-b bg-white py-6">
      <div className="mx-auto max-w-[1500px] px-6">
        <div className="flex items-center justify-between">
          <Link href="/">
            <Image
              src="/logo.png"
              alt="DjangoBnb logo"
              width={180}
              height={38}
            />
          </Link>

          <div className="flex space-x-6">
            <SearchFilters />
          </div>

          <div className="flex items-center space-x-6">
            <AddPropertyButton userId={userId} />

            <UserNav userId={userId} />
          </div>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
