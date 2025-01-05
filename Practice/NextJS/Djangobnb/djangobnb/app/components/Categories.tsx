import Image from "next/image";

const Categories = () => {
  return (
    <div className="flex cursor-pointer items-center space-x-12 pb-6 pt-3">
      <div className="flex flex-col items-center space-y-2 border-b-2 border-white pb-4 opacity-60 hover:border-gray-200 hover:opacity-100">
        <Image
          src="/icn_category_beach.jpeg"
          alt="Category - Beach"
          width={20}
          height={20}
        />

        <span className="text-xs">Beach</span>
      </div>

      <div className="flex flex-col items-center space-y-2 border-b-2 border-white pb-4 opacity-60 hover:border-gray-200 hover:opacity-100">
        <Image
          src="/icn_category_beach.jpeg"
          alt="Category - Beach"
          width={20}
          height={20}
        />

        <span className="text-xs">Villas</span>
      </div>

      <div className="flex flex-col items-center space-y-2 border-b-2 border-white pb-4 opacity-60 hover:border-gray-200 hover:opacity-100">
        <Image
          src="/icn_category_beach.jpeg"
          alt="Category - Beach"
          width={20}
          height={20}
        />

        <span className="text-xs">Cabins</span>
      </div>

      <div className="flex flex-col items-center space-y-2 border-b-2 border-white pb-4 opacity-60 hover:border-gray-200 hover:opacity-100">
        <Image
          src="/icn_category_beach.jpeg"
          alt="Category - Beach"
          width={20}
          height={20}
        />

        <span className="text-xs">Tiny homes</span>
      </div>
    </div>
  );
};

export default Categories;
