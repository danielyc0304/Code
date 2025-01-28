import Image from "next/image";

interface CategoriesProps {
  dataCategory: string;
  setCategory: (category: string) => void;
}

const Categories: React.FC<CategoriesProps> = ({
  dataCategory,
  setCategory,
}) => {
  return (
    <>
      <div className="flex cursor-pointer items-center space-x-12 pb-6 pt-3">
        <div
          onClick={() => setCategory("beach")}
          className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${dataCategory == "Beach" ? "border-gray-800" : "border-white"}`}
        >
          <Image
            src="/icn_category_beach.jpeg"
            alt="Category - Beach"
            width={20}
            height={20}
          />

          <span className="text-xs">Beach</span>
        </div>

        <div
          onClick={() => setCategory("villas")}
          className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${dataCategory == "Villas" ? "border-gray-800" : "border-white"}`}
        >
          <Image
            src="/icn_category_beach.jpeg"
            alt="Category - Beach"
            width={20}
            height={20}
          />

          <span className="text-xs">Villas</span>
        </div>

        <div
          onClick={() => setCategory("cabins")}
          className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${dataCategory == "Cabins" ? "border-gray-800" : "border-white"}`}
        >
          <Image
            src="/icn_category_beach.jpeg"
            alt="Category - Beach"
            width={20}
            height={20}
          />

          <span className="text-xs">Cabins</span>
        </div>

        <div
          onClick={() => setCategory("tiny_homes")}
          className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${dataCategory == "Tiny homes" ? "border-gray-800" : "border-white"}`}
        >
          <Image
            src="/icn_category_beach.jpeg"
            alt="Category - Beach"
            width={20}
            height={20}
          />

          <span className="text-xs">Tiny homes</span>
        </div>
      </div>
    </>
  );
};

export default Categories;
