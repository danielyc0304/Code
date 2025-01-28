from dj_rest_auth.jwt_auth import get_refresh_view
from dj_rest_auth.registration.views import RegisterView
from dj_rest_auth.views import LoginView, LogoutView

from django.urls import path

from . import api


urlpatterns = [
    path("login/", LoginView.as_view(), name="rest_login"),
    path("logout/", LogoutView.as_view(), name="rest_logout"),
    path("myreservations/", api.reservations_list, name="api_reservations_list"),
    path("register/", RegisterView.as_view(), name="rest_register"),
    path("token/refresh/", get_refresh_view().as_view(), name="token_refresh"),
    path("<uuid:pk>/", api.landlord_detail, name="api_landlrod_detail"),
]
