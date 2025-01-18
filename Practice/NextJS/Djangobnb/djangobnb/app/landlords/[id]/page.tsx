import Image from "next/image";

import ContactButton from "@/app/components/ContactButton";
import PropertyList from "@/app/components/properties/PropertyList";

import apiService from "@/app/services/apiService";
import { getUserId } from "@/app/lib/actions";

const LandlordDetailPage = async ({ params }: { params: { id: string } }) => {
  const landlord = await apiService.get(`/api/auth/${params.id}`);
  const userId = await getUserId();

  return (
    <main className="mx-auto max-w-[1500px] px-6 pb-6">
      <div className="grid grid-cols-1 gap-4 md:grid-cols-4">
        <aside className="col-span-1 mb-4">
          <div className="flex flex-col items-center rounded-xl border border-gray-300 p-6 shadow-xl">
            <Image
              src={landlord.avatar_url}
              width={200}
              height={200}
              alt="Landlrod name"
              className="rounded-full"
            />

            <h1 className="mt-6 text-2xl">{landlord.name}</h1>

            {userId != params.id && <ContactButton />}
          </div>
        </aside>

        <div className="col-span-1 pl-0 md:col-span-3 md:pl-6">
          <div className="grid grid-cols-1 gap-6 md:grid-cols-3">
            <PropertyList landlord_id={params.id} />
          </div>
        </div>
      </div>
    </main>
  );
};

export default LandlordDetailPage;
