"use server";

import { cookies } from "next/headers";

export async function handleRefresh() {
  console.log("handleRefresh");

  const refreshToken = await getRefreshToken();

  const token = await fetch("http://localhost:8000/api/auth/token/refresh/", {
    method: "POST",
    body: JSON.stringify({ refresh: refreshToken }),
    headers: { Accept: "application/json", "Content-Type": "application/json" },
  })
    .then((response) => response.json())
    .then((json) => {
      console.log("Response - Refresh:", json);

      if (json.access) {
        cookies().set("session_access_token", json.access, {
          httpOnly: true,
          secure: process.env.NODE_ENV === "production",
          maxAge: 60 * 60,
          path: "/",
        });

        return json.access;
      } else {
        resetAuthCookies();
      }
    })
    .catch((error) => {
      console.log("error", error);

      resetAuthCookies();
    });

  return token;
}

export async function handleLogin(
  userId: string,
  accessToken: string,
  refreshToken: string,
) {
  cookies().set("session_userid", userId, {
    httpOnly: true,
    secure: process.env.NODE_ENV === "production",
    maxAge: 60 * 60 * 24 * 7,
    path: "/",
  });

  cookies().set("session_access_token", accessToken, {
    httpOnly: true,
    secure: process.env.NODE_ENV === "production",
    maxAge: 60 * 60,
    path: "/",
  });

  cookies().set("session_refresh_token", refreshToken, {
    httpOnly: true,
    secure: process.env.NODE_ENV === "production",
    maxAge: 60 * 60 * 24 * 7,
    path: "/",
  });
}

export async function resetAuthCookies() {
  cookies().set("session_userid", "");
  cookies().set("session_access_token", "");
  cookies().set("session_refresh_token", "");
}

export async function getUserId() {
  const userId = cookies().get("session_userid")?.value;

  return userId ? userId : null;
}

export async function getAccessToken() {
  let accessToken = cookies().get("session_access_token")?.value;

  if (!accessToken) {
    accessToken = await handleRefresh();
  }

  return accessToken;
}

export async function getRefreshToken() {
  let refreshToken = cookies().get("session_refresh_token")?.value;

  return refreshToken;
}
