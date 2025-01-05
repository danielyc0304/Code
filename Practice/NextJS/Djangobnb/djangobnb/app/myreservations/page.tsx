import Image from "next/image";

const MyReservationsPage = () => {
  return (
    <main className="mx-auto max-w-[1500px] px-6 pb-6">
      <h1 className="my-6 text-2xl">My reservations</h1>

      <div className="space-y-4">
        <div className="grid grid-cols-1 gap-4 rounded-xl border border-gray-300 p-5 shadow-md md:grid-cols-4">
          <div className="col-span-1">
            <div className="relative aspect-square overflow-hidden rounded-xl">
              <Image
                fill
                src="/beach_1.jpg"
                className="h-full w-full object-cover transition hover:scale-110"
                alt="Beach house"
              />
            </div>
          </div>

          <div className="col-span-1 md:col-span-3">
            <h2 className="mb-4 text-xl">Property name</h2>

            <p className="mb-2">
              <strong>Check in date:</strong> 14/2/2024
            </p>
            <p className="mb-2">
              <strong>Check out date:</strong> 16/2/2024
            </p>

            <p className="mb-2">
              <strong>Number of nights:</strong> 2
            </p>
            <p className="mb-2">
              <strong>Total price:</strong> $200
            </p>

            <div className="bg-airbnb mt-6 inline-block cursor-pointer rounded-xl px-6 py-4 text-white">
              Go to property
            </div>
          </div>
        </div>

        <div className="grid grid-cols-1 gap-4 rounded-xl border border-gray-300 p-5 shadow-md md:grid-cols-4">
          <div className="col-span-1">
            <div className="relative aspect-square overflow-hidden rounded-xl">
              <Image
                fill
                src="/beach_1.jpg"
                className="h-full w-full object-cover transition hover:scale-110"
                alt="Beach house"
              />
            </div>
          </div>

          <div className="col-span-1 md:col-span-3">
            <h2 className="mb-4 text-xl">Property name</h2>

            <p className="mb-2">
              <strong>Check in date:</strong> 14/2/2024
            </p>
            <p className="mb-2">
              <strong>Check out date:</strong> 16/2/2024
            </p>

            <p className="mb-2">
              <strong>Number of nights:</strong> 2
            </p>
            <p className="mb-2">
              <strong>Total price:</strong> $200
            </p>

            <div className="bg-airbnb mt-6 inline-block cursor-pointer rounded-xl px-6 py-4 text-white">
              Go to property
            </div>
          </div>
        </div>
      </div>
    </main>
  );
};

export default MyReservationsPage;
