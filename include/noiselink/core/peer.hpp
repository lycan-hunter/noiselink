#include <fstream>
#include <string>
#include <vector>
#include <toml++/toml.hpp>
#include <cstdint>
#include <noiselink/core/turn_server.hpp>
#include <filesystem>
#include <memory>

namespace noiselink {
    namespace fs = std::filesystem;

struct PeerProfile {
    // [identity]
    struct Identity {
        std::string node_name = "NoiseLink-Node";
        std::string public_key;
        std::string virtual_ip = "10.9.0.1";
    } identity;

    // [remote_peer]
    struct RemotePeer {
        std::string peer_public_key;
        std::string peer_virtual_ip = "10.9.0.2";
    } remote;

    // [network]
    struct Network {
        std::vector<std::string> stun_servers = {
            "stun:stun.l.google.com:19302",
            "stun:stun1.l.google.com:19305"
        };
        std::vector<TurnServer> turn_servers;
    } network;

    // [steganography]
    struct Steganography {
        std::string mode = "lsb_audio";
        bool enabled = true;
        std::string passphrase_hash;
        float noise_density = 0.85f;
    } stego;

    // [system]
    struct System {
        std::string interface_name = "utun0";
        uint32_t mtu = 1300;
        bool allow_global_traffic = false;
    } system;
};


class Peer {
 public:
  std::unique_ptr<PeerProfile> profile = nullptr;
  void load_profile(const fs::path &profile_path);
  void create_profile_file();
  bool is_connected()const{return is_connected;};

 private:
  void parse_loaded_profile();
  bool is_connected = false;
  
};

};  // namespace noiselink