#pragma once

#include <json.hpp>
#include <mutex>

using json = nlohmann::json;

namespace stateline
{
  class ApiResources {
    public:
      std::string get(const std::string& resource);
      std::string getAll();
      void set(const std::string& resource, json data);

    private:
      std::map<std::string, std::string> resources_;
      std::mutex mutex_;
  };

  void runApiServer(uint port, ApiResources& res, bool& running);
}
