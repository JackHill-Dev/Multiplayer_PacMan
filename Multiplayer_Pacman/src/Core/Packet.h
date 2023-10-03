#pragma once
#include <cstdint>
#include <SFML/Network/Packet.hpp>
#include <memory>
enum class PacketType : uint8_t
{
	Join,
	GameState,
	PlayerData
};

class Packet
{
public:
	Packet() : m_data(new sf::Packet) {}
	virtual ~Packet() {}

	virtual void Write(sf::Packet& packet)
	{
		packet << static_cast<uint8_t>(m_type);
	}
	virtual void Read(sf::Packet& packet) 
	{
		uint8_t type;
		packet >> type;
		m_type = static_cast<PacketType>(type);
	}

protected:
	PacketType m_type;
	std::unique_ptr<sf::Packet> m_data;
};

class JoinPacket : public Packet
{
public:
	JoinPacket() { m_type = PacketType::Join; }

	virtual void Write(sf::Packet& packet) override
	{
		Packet::Write(packet);
		packet << m_PlayerName;
	}

	virtual void Read(sf::Packet& packet) override
	{
		Packet::Read(packet);
		packet >> m_PlayerName;
	}

	const std::string& GetPlayerName() const { return m_PlayerName; }
	void SetPlayerName(const std::string& name) { m_PlayerName = name; }

private:
	std::string m_PlayerName;

};