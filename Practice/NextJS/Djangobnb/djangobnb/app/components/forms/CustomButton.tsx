interface CustomButtonProps {
  label: string;
  className?: string;
  onClick: () => void;
}

const CustomButton: React.FC<CustomButtonProps> = ({
  label,
  className,
  onClick,
}) => {
  return (
    <div
      onClick={onClick}
      className={`bg-airbnb hover:bg-airbnb-dark w-full cursor-pointer rounded-xl py-4 text-center text-white transition ${className}`}
    >
      {label}
    </div>
  );
};

export default CustomButton;
