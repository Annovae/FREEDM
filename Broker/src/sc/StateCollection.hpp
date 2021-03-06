////////////////////////////////////////////////////////////////////////////////
/// @file         StateCollection.hpp
///
/// @author       Li Feng <lfqt5@mail.mst.edu>
/// @author       Derek Ditch <derek.ditch@mst.edu>
///
/// @project      FREEDM DGI
///
/// @description  state collection module
///
/// These source code files were created at Missouri University of Science and
/// Technology, and are intended for use in teaching or research. They may be
/// freely copied, modified, and redistributed as long as modified versions are
/// clearly marked as such and this notice is not removed. Neither the authors
/// nor Missouri S&T make any warranty, express or implied, nor assume any legal
/// responsibility for the accuracy, completeness, or usefulness of these files
/// or any information distributed with these files.
///
/// Suggested modifications or questions about these files can be directed to
/// Dr. Bruce McMillin, Department of Computer Science, Missouri University of
/// Science and Technology, Rolla, MO 65409 <ff@mst.edu>.
////////////////////////////////////////////////////////////////////////////////

#ifndef CSTATECOLLECTION_HPP_
#define CSTATECOLLECTION_HPP_

#include "CMessage.hpp"
#include "IAgent.hpp"
#include "IHandler.hpp"
#include "IPeerNode.hpp"

#include <map>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/property_tree/ptree.hpp>

namespace freedm
{

namespace broker
{

namespace sc
{

using boost::property_tree::ptree;

///////////////////////////////////////////////////////////////////////////////
/// @class          SCAgent
/// @description    Declaration of Chandy-Lamport Algorithm
///                 Each node that wants to initiate the state collection records its
///                 local state and sends a marker message to all other peer nodes.
///             Upon receiving a marker for the first time, peer nodes record their local states
///                 and start recording any message from incoming channel until receive marker from
///                 other nodes (these messages belong to the channel between the nodes).
///////////////////////////////////////////////////////////////////////////////

class SCAgent : public IReadHandler, private IPeerNode,
        public IAgent< boost::shared_ptr<IPeerNode> >
{
    public:
        ///Constructor
        SCAgent(std::string uuid);

    private:
        //Marker structure
        typedef std::pair< std::string, int >  StateVersion;

        //Handler
        ///Handle receiving messages
        void HandleAny(MessagePtr msg, PeerNodePtr peer);
        void HandlePeerList(MessagePtr msg, PeerNodePtr peer);
        void HandleRequest(MessagePtr msg, PeerNodePtr peer);
        void HandleMarker(MessagePtr msg, PeerNodePtr peer);
        void HandleState(MessagePtr msg, PeerNodePtr peer);

        //Internal
        ///Initiator starts state collection
        void    Initiate();
        ///Save local state
        void    TakeSnapshot(const std::vector<std::string>& devicelist);
        ///Peer sends collected states back to the initiator
        void    SendStateBack();
        ///Initiator sends collected states back to the request module
        void    StateResponse();
        ///Peer save local state and forward maker
        void    SaveForward(StateVersion latest, CMessage msg);

        // Messages
        ///Create a marker message
        CMessage marker();

        //Peer set operations
        ///Add a peer to peer set from a pointer to a peer node object
        PeerNodePtr AddPeer(PeerNodePtr peer);
        ///Get a pointer to a peer from UUID
        PeerNodePtr GetPeer(std::string uuid);

        ///collect states container and its iterator
        std::multimap<StateVersion, ptree> collectstate;
        std::multimap<StateVersion, ptree>::iterator it;

        ///count number of states
        unsigned int m_countstate;
        ///count number of marker
        unsigned int m_countmarker;
        ///count number of "Done" messages
        unsigned int m_countdone;

        ///save leader
        std::string m_scleader;

        ///flag to indicate save channel message
        bool m_NotifyToSave;

        ///module that request state collection
        std::string m_module;

        ///number of requested device
        unsigned int m_deviceNum;

        //For multidevices state collection the following variables have to be changed
        std::vector<std::string> m_device;

        ///current version of marker
        StateVersion        m_curversion;
        ///current state
        ptree               m_curstate;

        ///all known peers
        PeerSet m_AllPeers;
};

} // namespace sc

} // namespace broker

} // namespace freedm

#endif


