import Image from "next/image";

const PropertyListItem = () => {
  return (
    <div className="cursor-pointer">
      <div className="relative aspect-square overflow-hidden rounded-xl">
        <Image
          fill
          src="/beach_1.jpg"
          sizes="(max-width: 768px) 768px, (max-width: 1200px): 768px, 768px"
          className="h-full w-full object-cover transition hover:scale-110"
          alt="Beach house"
        />
      </div>

      <div className="mt-2">
        <p className="text-lg font-bold">Property name</p>
      </div>

      <div className="mt-2">
        <p className="text-sm text-gray-500">
          <strong>$200</strong> per night
        </p>
      </div>
    </div>
  );
};

export default PropertyListItem;
