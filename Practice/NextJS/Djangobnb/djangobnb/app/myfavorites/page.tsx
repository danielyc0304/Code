import PropertyList from "../components/properties/PropertyList";

import { getUserId } from "../lib/actions";

const MyFavoritesPage = async () => {
  const userId = await getUserId();

  if (!userId) {
    return (
      <main className="max-auto max-w-[1500px] px-6 py-12">
        <p>You need to be authenticated...</p>
      </main>
    );
  }

  return (
    <main className="max-auto max-w-[1500px] px-6 pb-12">
      <h1 className="my-6 text-2xl">My favorites</h1>

      <div className="grid grid-cols-1 gap-6 md:grid-cols-3">
        <PropertyList favorites={true} />
      </div>
    </main>
  );
};

export default MyFavoritesPage;
