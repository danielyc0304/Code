"use client";

import { useState } from "react";
import Image from "next/image";

import useSearchModal, { SearchQuery } from "../hooks/useSearchModal";

const Categories = () => {
  const [category, setCategory] = useState("");
  const searchModal = useSearchModal();

  const _setCategory = (_category: string) => {
    setCategory(_category);

    const query: SearchQuery = {
      country: searchModal.query.country,
      checkIn: searchModal.query.checkIn,
      checkOut: searchModal.query.checkOut,
      guests: searchModal.query.guests,
      bedrooms: searchModal.query.bedrooms,
      bathrooms: searchModal.query.bathrooms,
      category: _category,
    };

    searchModal.setQuery(query);
  };

  return (
    <div className="flex cursor-pointer items-center space-x-12 pb-6 pt-3">
      <div
        onClick={() => _setCategory("")}
        className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${category == "" ? "border-black" : "border-white"}`}
      >
        <Image
          src="/icn_category_beach.jpeg"
          alt="Category - Beach"
          width={20}
          height={20}
        />

        <span className="text-xs">All</span>
      </div>

      <div
        onClick={() => _setCategory("beach")}
        className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${category == "beach" ? "border-black" : "border-white"}`}
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
        onClick={() => _setCategory("villas")}
        className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${category == "villas" ? "border-black" : "border-white"}`}
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
        onClick={() => _setCategory("cabins")}
        className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${category == "cabins" ? "border-black" : "border-white"}`}
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
        onClick={() => _setCategory("tiny_homes")}
        className={`flex flex-col items-center space-y-2 border-b-2 pb-4 opacity-60 hover:border-gray-200 hover:opacity-100 ${category == "tiny_homes" ? "border-black" : "border-white"}`}
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
  );
};

export default Categories;
