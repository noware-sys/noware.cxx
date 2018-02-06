#pragma once

#include "../net/cast.hxx"
#include <string>
#include <zmq/msg.hxx>
#include <zyre.h>
#include <zyre.hxx>
//#include <noware/nr.hxx>
#include <cln/nr.hxx>

namespace noware
{
	// Place in another project (kernel/os?)?
	namespace cluster
	{
		// resource rsrc rsc
		// device dev
		class node
			//: misc::instance
		{
			public:
				node (void);
				virtual ~node (void);
				
				virtual const bool fin (void);
				virtual const bool inited (void) const;
				virtual const bool init (void);
				
				virtual const bool stop (void);
				virtual const bool running (void) const;
				virtual const bool start (void);
				
				// Could be reimplemented in the inheriting, device-specific, class.
				virtual const bool disable (void);
				virtual const bool enabled (void) const;
				virtual const bool enable (void);
				
				//virtual const noware::var evaluate (const noware::var &/* expression*/);
				// local value
				virtual const zmq::msg/* value*/ locval (const zmq::msg &/* expression*/);
				virtual const zmq::msg/* value*/ unival (const zmq::msg &/* expression*/, const std::string &/* peer (id)*/);
				virtual const zmq::msg/* value*/ anyval (const zmq::msg &/* expression*/);
				virtual const zmq::msg/* value*/ anyval (const zmq::msg &/* expression*/, const std::string &/* (zyre) group*/);
				virtual const zmq::msg/* value*/ multival (const zmq::msg &/* expression*/, const std::string &/* (zyre) group*/ = grp_dft);
				virtual const zmq::msg/* value*/ broadval (const zmq::msg &/* expression*/);
				
				//virtual const noware::var/* value*/ get (const noware::var &/* key*/) const;
				//virtual const bool/* success*/ set (const noware::var &/* key*/, const noware::var &/* value*/);
				
				// Transmit a message to one node.
				virtual const zmq::msg/* message: response*/ unicast (zmq::msg/* message: request*/, const std::string &/* peer (id)*/);
				
				// Transmit a message to any one node amongst all nodes.
				virtual const zmq::msg/* message: response*/ anycast (zmq::msg/* message: request*/, std::string &/* destination (peer_id)*/);
				
				// Transmit a message to any one node belonging to a group.
				virtual const zmq::msg/* message: response*/ anycast (zmq::msg/* message: request*/, std::string &/* destination (peer_id)*/, const std::string &/* group*/);
				
				// Transmit a message to all nodes belonging to a group.
				// Main usage: request other nodes to perform an operation.
				virtual const zmq::msg/* message: response*/ multicast (zmq::msg/* message: request*/, cln::nr &/* responses_count: to be written to*//* number of peers who returned a response*/, std::string const &/* (zyre) group*/ = grp_dft);
				
				// Transmit a message to all nodes.
				virtual const zmq::msg/* message: response*/ broadcast (zmq::msg/* message: request*/, cln::nr &/* responses_count: to be written to*//* number of peers who returned a response*/);
				
			//protected:
				//static net::cluster nodes;
				//net::node node;
				/*zmq::*/zyre _node;
			protected:
			//private:
				// Manager of received messages.
				virtual void rx (zyre_event_t * const/* zyre_event*/);
				
				// Receives the response from the query.
				//virtual const noware::var receive_local (const std::string &/* response_type*/, const std::string &/* filter*/ = "") const;
				//virtual const zmq::msg receive_local (cln::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* (zyre) group (to receive from (where the message was sent to))*/ = /*noware::machine::device::*/grp_dft) const;
				virtual const zmq::msg rx_local (const std::string &/* request_token*/, const cln::nr &/* number of expected responses*/, cln::nr &/* responses_count*//* number of peers who actually answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/) const;
				
				// Transmits/Redirect the response to the thread who queried it.
				//virtual const bool unicast_local (const zmq::msg &/* message*/) const;
				virtual const bool unicast_local (const zmq::msg &/* message*/, const std::string &/* request_token*/) const;
				//virtual const bool unicast_local (const zmsg_t */* message*/) const;
				
				static const std::string grp_dft;
				static const cln::nr token_size_dft;
				
				// Internal proxy
				//zmq::context_t * local_context;
				////zmq::context_t local_context {1};
				//zmq::socket_t * local_socket;
				////void local_reception (void);
				
				//
				// Only these functions
				// need to be implemented
				// by the inheriting class:
				//
				////virtual const noware::tree <>/* response*/ respond (const noware::tree <> &/* message*/);
				//virtual const bool/* success*/ respond (const /*zmq::msg &*/zmsg_t */* message*/, const zyre_event_t */* (zyre) event*/);
				
				virtual const bool/* success*/ respond (zmq::msg &/* response*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				virtual const bool/* success*/ respond_post (const zmq::msg &/* response (read-only)*/, const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/, const bool &/* result*/);
				//virtual const bool/* success*/ rx_response (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ rx_request (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ request (const zyre_event_t */* (zyre) event*/);
			//	virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				//virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
				virtual const bool/* success*/ infrastruct (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
				virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/, const std::string &/* src*/, const net::cast &/* src_cast*/);// const
				virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/, const cln::nr &/* responses_count*//* number of peers who answered*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
		};
	}
}
