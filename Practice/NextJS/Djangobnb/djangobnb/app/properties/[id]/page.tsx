import Image from "next/image";

import ReservationSidebar from "@/app/components/properties/ReservationSidebar";

import apiService from "@/app/services/apiService";

const PropertyDetailPage = async ({ params }: { params: { id: string } }) => {
  const property = await apiService.get(`/api/properties/${params.id}`);

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
          <h1 className="mb-4 text-4xl">{property.title}</h1>

          <span className="mb-6 block text-lg text-gray-600">
            {property.guests} guests - {property.bedrooms} bedrooms -{" "}
            {property.bathrooms} bathroom
          </span>

          <hr />

          <div className="flex items-center space-x-4 py-6">
            {property.landlord.avatar_url && (
              <Image
                src={property.landlord.avatar_url}
                width={50}
                height={50}
                className="rounded-full"
                alt="The user name"
              />
            )}

            <p>
              <strong>{property.landlord.name}</strong> is your host
            </p>
          </div>

          <hr />

          <p className="mt-6 text-lg">{property.description}</p>
        </div>

        <ReservationSidebar property={property} />
      </div>
    </main>
  );
};

export default PropertyDetailPage;
