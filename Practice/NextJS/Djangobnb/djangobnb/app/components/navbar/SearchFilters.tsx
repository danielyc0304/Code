"use client";

import useSearchModal from "@/app/hooks/useSearchModal";

const SearchFilters = () => {
  const searchModal = useSearchModal();

  return (
    <div
      onClick={() => searchModal.open('location')}
      className="flex h-[48px] flex-row items-center justify-between rounded-full border lg:h-[64]"
    >
      <div className="hidden lg:block">
        <div className="flex flex-row items-center justify-between">
          <div className="flex h-[48px] w-[250px] cursor-pointer flex-col justify-center rounded-full px-8 hover:bg-gray-100 lg:h-[64]">
            <p className="text-xs font-semibold">Where</p>
            <p className="text-sm">Wanted location</p>
          </div>

          <div className="flex h-[48px] cursor-pointer flex-col justify-center rounded-full px-8 hover:bg-gray-100 lg:h-[64]">
            <p className="text-xs font-semibold">Check in</p>
            <p className="text-sm">Add dates</p>
          </div>

          <div className="flex h-[48px] cursor-pointer flex-col justify-center rounded-full px-8 hover:bg-gray-100 lg:h-[64]">
            <p className="text-xs font-semibold">Check out</p>
            <p className="text-sm">Add dates</p>
          </div>

          <div className="flex h-[48px] cursor-pointer flex-col justify-center rounded-full px-8 hover:bg-gray-100 lg:h-[64]">
            <p className="text-xs font-semibold">Who</p>
            <p className="text-sm">Add guests</p>
          </div>
        </div>
      </div>

      <div className="p-2">
        <div className="cursor-pointer rounded-full bg-airbnb p-2 text-white transition hover:bg-airbnb-dark lg:p-4">
          <svg
            viewBox="0 0 32 32"
            style={{
              display: "block",
              fill: "none",
              height: "16px",
              width: "16px",
              stroke: "currentColor",
              strokeWidth: 4,
              overflow: "visible",
            }}
            aria-hidden="true"
            role="presentation"
            focusable="false"
          >
            <path
              fill="none"
              d="M13 24a11 11 0 1 0 0-22 11 11 0 0 0 0 22zm8-3 9 9"
            ></path>
          </svg>
        </div>
      </div>
    </div>
  );
};

export default SearchFilters;
