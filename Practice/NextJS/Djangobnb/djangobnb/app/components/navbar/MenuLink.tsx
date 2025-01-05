"use client";

interface MenuLinkProps {
  label: string;
  onClick: () => void;
}

const MenuLink: React.FC<MenuLinkProps> = ({ label, onClick }) => {
  return (
    <div
      onClick={onClick}
      className="cursor-pointer px-5 py-4 transition hover:bg-gray-100"
    >
      {label}
    </div>
  );
};

export default MenuLink;
