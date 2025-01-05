import Image from "next/image";

import ReservationSidebar from "@/app/components/properties/ReservationSidebar";

const PropertyDetailPage = () => {
  return (
    <main className="mx-auto max-w-[1500px] px-6 pb-6">
      <div className="relative mb-4 h-[64vh] w-full overflow-hidden rounded-xl">
        <Image
          fill
          src="/beach_1.jpg"
          className="h-full w-full object-cover"
          alt="Beach house"
        />
      </div>

      <div className="grid grid-cols-1 gap-4 md:grid-cols-5">
        <div className="col-span-3 py-6 pr-6">
          <h1 className="mb-4 text-4xl">Protpery name</h1>

          <span className="mb-6 block text-lg text-gray-600">
            4 guests - 2 bedrooms - 1 bathroom
          </span>

          <hr />

          <div className="flex items-center space-x-4 py-6">
            <Image
              src="/profile_pic_1.jpg"
              width={50}
              height={50}
              className="rounded-full"
              alt="The user name"
            />

            <p>
              <strong>John Doe</strong> is your host
            </p>
          </div>

          <hr />

          <p className="mt-6 text-lg">
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Iusto
            delectus quis non nobis, quia corporis dolore ea quidem culpa
            tempora sit odit, eum magni eveniet unde veritatis cumque debitis.
            Iste.
          </p>
        </div>

        <ReservationSidebar />
      </div>
    </main>
  );
};

export default PropertyDetailPage;
