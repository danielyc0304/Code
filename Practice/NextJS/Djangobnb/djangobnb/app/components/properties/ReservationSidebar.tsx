const ReservationSidebar = () => {
  return (
    <aside className="col-span-2 mt-6 rounded-xl border border-gray-300 p-6 shadow-xl">
      <h2 className="mb-5 text-2xl">$200 per night</h2>

      <div className="mb-6 rounded-xl border border-gray-400 p-3">
        <label className="mb-2 block text-xs font-bold">Guests</label>

        <select className="text-xm -ml-1 w-full">
          <option>1</option>
          <option>2</option>
          <option>3</option>
          <option>4</option>
        </select>
      </div>

      <div className="bg-airbnb hover:bg-airbnb-dark mb-6 w-full rounded-xl py-6 text-center text-white">
        Book
      </div>

      <div className="align-center mb-4 flex justify-between">
        <p>$200 * 4 nights</p>

        <p>$800</p>
      </div>

      <div className="align-center mb-4 flex justify-between">
        <p>Djangobnb fee</p>

        <p>$40</p>
      </div>

      <hr />

      <div className="align-center mt-4 flex justify-between font-bold">
        <p>Total</p>

        <p>$840</p>
      </div>
    </aside>
  );
};

export default ReservationSidebar;
