"use client";

import CustomButton from "../forms/CustomButton";

const ConversationDetail = () => {
  return (
    <>
      <div className="flex max-h-[400px] flex-col space-y-4 overflow-auto">
        <div className="w-[80%] rounded-xl bg-gray-200 px-6 py-4">
          <p className="font-bold text-gray-500">John Doe</p>

          <p>
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Debitis ea
            unde nemo obcaecati laborum sequi sunt magnam inventore, voluptatum
            atque! Deserunt impedit maxime explicabo blanditiis repellat sint ad
            quod vero.
          </p>
        </div>

        <div className="ml-[20%] w-[80%] rounded-xl bg-blue-200 px-6 py-4">
          <p className="font-bold text-gray-500">Code With Stein</p>

          <p>
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Debitis ea
            unde nemo obcaecati laborum sequi sunt magnam inventore, voluptatum
            atque! Deserunt impedit maxime explicabo blanditiis repellat sint ad
            quod vero.
          </p>
        </div>
      </div>

      <div className="mt-4 flex space-x-4 rounded-xl border border-gray-300 px-6 py-4">
        <input
          type="text"
          placeholder="Type your message..."
          className="w-full rounded-xl bg-gray-200 p-2"
        />

        <CustomButton
          label="Send"
          onClick={() => console.log("Clicked")}
          className="w-[100px]"
        />
      </div>
    </>
  );
};

export default ConversationDetail;
