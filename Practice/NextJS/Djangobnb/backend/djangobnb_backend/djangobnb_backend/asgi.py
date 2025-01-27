import os

from channels.routing import ProtocolTypeRouter, URLRouter

from chat import routing
from chat.token_auth import TokenAuthMiddleware

from django.core.asgi import get_asgi_application


os.environ.setdefault("DJANGO_SETTINGS_MODULE", "djangobnb_backend.settings")

application = get_asgi_application()

application = ProtocolTypeRouter(
    {
        "http": get_asgi_application(),
        "websocket": TokenAuthMiddleware(URLRouter(routing.websocket_urlpatterns)),
    }
)
