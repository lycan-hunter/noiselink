#include <fstream>
#include <string>
#include <vector>
#include <toml++/toml.hpp>
#include <cstdint>
#include <noiselink/core/turn_server.hpp>
#include <noiselink/core/peer.hpp>
#include <filesystem>
#include <memory>
#include <stdexcept>

namespace noiselink {
    namespace fs = std::filesystem;

  void Peer::load_profile(const fs::path &profile_path){
    if (profile!=nullptr){
        throw std::logic_error("Profile already loaded, clear profile before loading !");
    }
    this->profile = std::make_unique<PeerProfile>();
    
    auto cfg = toml::parse_file(profile_path.c_str());
    // profile->identity.node_name = cfg["identity"]["node_name"].value_or("NoiseLink-Node");
    // profile->identity.public_key = cfg["identity"]["public_key"].value_or();

}
  void Peer::create_profile_file(){};
  void Peer::parse_loaded_profile(){};

};  // namespace noiselink