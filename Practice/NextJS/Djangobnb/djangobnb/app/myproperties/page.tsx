import PropertyList from "../components/properties/PropertyList";

import { getUserId } from "../lib/actions";

const MyPropertiesPage = async () => {
  const userId = await getUserId();

  return (
    <main className="mx-auto max-w-[1500px] px-6 pb-6">
      <h1 className="my-6 text-2xl">My properties</h1>

      <div className="grid grid-cols-1 gap-6 md:grid-cols-3">
        <PropertyList landlord_id={userId} />
      </div>
    </main>
  );
};

export default MyPropertiesPage;
