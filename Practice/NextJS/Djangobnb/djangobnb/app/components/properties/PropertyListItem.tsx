import Image from "next/image";
import { useRouter } from "next/navigation";

import { PropertyType } from "./PropertyList";
import FavoriteButton from "../FavoriteButton";

interface PropertyProps {
  property: PropertyType;
  markFavorite: (is_favorite: boolean) => void;
}

const PropertyListItem: React.FC<PropertyProps> = ({
  property,
  markFavorite,
}) => {
  const router = useRouter();

  return (
    <div
      className="cursor-pointer"
      onClick={() => router.push(`/properties/${property.id}`)}
    >
      <div className="relative aspect-square overflow-hidden rounded-xl">
        <Image
          fill
          src={property.image_url}
          sizes="(max-width: 768px) 768px, (max-width: 1200px): 768px, 768px"
          className="h-full w-full object-cover transition hover:scale-110"
          alt="Beach house"
        />

        {markFavorite && (
          <FavoriteButton
            id={property.id}
            is_favorite={property.is_favorite}
            markFavorite={(is_favorite) => markFavorite(is_favorite)}
          />
        )}
      </div>

      <div className="mt-2">
        <p className="text-lg font-bold">{property.title}</p>
      </div>

      <div className="mt-2">
        <p className="text-sm text-gray-500">
          <strong>${property.price_per_night}</strong> per night
        </p>
      </div>
    </div>
  );
};

export default PropertyListItem;
