import Image from "next/image";
import Link from "next/link";

import apiService from "../services/apiService";

const MyReservationsPage = async () => {
  const reservations = await apiService.get("/api/auth/myreservations/");

  return (
    <main className="mx-auto max-w-[1500px] px-6 pb-6">
      <h1 className="my-6 text-2xl">My reservations</h1>

      <div className="space-y-4">
        {reservations.map((reservation: any) => {
          return (
            <div className="grid grid-cols-1 gap-4 rounded-xl border border-gray-300 p-5 shadow-md md:grid-cols-4">
              <div className="col-span-1">
                <div className="relative aspect-square overflow-hidden rounded-xl">
                  <Image
                    fill
                    src={reservation.property.image_url}
                    className="h-full w-full object-cover transition hover:scale-110"
                    alt="Beach house"
                  />
                </div>
              </div>

              <div className="col-span-1 md:col-span-3">
                <h2 className="mb-4 text-xl">{reservation.property.title}</h2>

                <p className="mb-2">
                  <strong>Check in date:</strong> {reservation.start_date}
                </p>
                <p className="mb-2">
                  <strong>Check out date:</strong> {reservation.end_date}
                </p>

                <p className="mb-2">
                  <strong>Number of nights:</strong>{" "}
                  {reservation.number_of_nights}
                </p>
                <p className="mb-2">
                  <strong>Total price:</strong> ${reservation.total_price}
                </p>

                <Link
                  href={`/properties/${reservation.property.id}`}
                  className="mt-6 inline-block cursor-pointer rounded-xl bg-airbnb px-6 py-4 text-white"
                >
                  Go to property
                </Link>
              </div>
            </div>
          );
        })}
      </div>
    </main>
  );
};

export default MyReservationsPage;
