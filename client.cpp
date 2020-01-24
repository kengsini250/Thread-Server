#include "client.h"

Client::Client(qintptr id)
{
    setSocketDescriptor(id);
}
