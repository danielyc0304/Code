"use client";

import {
  ClientSideSuspense,
  LiveblocksProvider,
  RoomProvider,
} from "@liveblocks/react/suspense";
import { useParams } from "next/navigation";
import { ReactNode } from "react";

export function Room({ children }: { children: ReactNode }) {
  const params = useParams();

  return (
    <LiveblocksProvider
      publicApiKey={
        "pk_dev_vMp36Y6VPkDNe2yuKyDkinW6Wqz-RsK4DjsYo35XRCmjuM2zy4OdWUtAmzHZ4dbc"
      }
    >
      <RoomProvider id={params.documentId as string}>
        <ClientSideSuspense fallback={<div>Loading…</div>}>
          {children}
        </ClientSideSuspense>
      </RoomProvider>
    </LiveblocksProvider>
  );
}
