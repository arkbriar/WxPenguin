#include "wxclient.hpp"
#include "json/json.hpp"

using json = nlohmann::json;

using WxClient = WebWx::WxClient;

void WxClient::ControlOnSync(const Model::WxSyncResponse &res)
{
    /*@TODO
     */
}
