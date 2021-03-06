#pragma once

#include "cast.hxx"
#include <string>
#include <zmq/msg.hxx>
#include <zyre.h>
#include <zyre.hxx>
#include <noware/random/string.hxx>
#include <cln/nr.hxx>

namespace noware
{
	// Place in another project (kernel/os?)?
	namespace net
	{
		// resource rsrc rsc
		// device dev
		class node
			//: misc::instance
		{
			public:
				node (void);
				virtual ~node (void);
				
				virtual bool const init (void);
				virtual bool const termin (void);
				virtual bool const inited (void) const;
				
				virtual bool const start (void);
				virtual bool const stop (void);
				virtual bool const running (void) const;
				
				// Could be reimplemented in the inheriting, device-specific, class.
				virtual bool const enable (void);
				virtual bool const disable (void);
				virtual bool const enabled (void) const;
				
				//virtual const noware::var evaluate (const noware::var &/* expression*/);
				// local value
				virtual zmq::msg const/* value*/ locval (zmq::msg const &/* expression*/);
				virtual zmq::msg const/* value*/ unival (zmq::msg const &/* expression*/, std::string const &/* peer (id)*/);
				virtual zmq::msg const/* value*/ anyval (zmq::msg const &/* expression*/);
				virtual zmq::msg const/* value*/ anyval (zmq::msg const &/* expression*/, std::string const &/* (zyre) group*/);
				virtual zmq::msg const/* value*/ multival (zmq::msg const &/* expression*/, std::string const &/* (zyre) group*/ = grp_dft);
				virtual zmq::msg const/* value*/ broadval (zmq::msg const &/* expression*/);
				
				//virtual const noware::var/* value*/ get (const noware::var &/* key*/) const;
				//virtual const bool/* success*/ set (const noware::var &/* key*/, const noware::var &/* value*/);
				
				// Transmit a message to one node.
				virtual zmq::msg const/* message: response*/ unicast (zmq::msg/* message: request*/, std::string const &/* peer (id)*/);
				
				// Transmit a message to any one node amongst all nodes.
				virtual zmq::msg const/* message: response*/ anycast (zmq::msg/* message: request*/, std::string &/* destination (peer_id)*/);
				
				// Transmit a message to any one node belonging to a group.
				virtual zmq::msg const/* message: response*/ anycast (zmq::msg/* message: request*/, std::string &/* destination (peer_id)*/, std::string const &/* group*/);
				
				// Transmit a message to all nodes belonging to a group.
				// Main usage: request other nodes to perform an operation.
				virtual zmq::msg const/* message: response*/ multicast (zmq::msg/* message: request*/, cln::nr &/* responses_count: to be written to*//* number of peers who returned a response*/, std::string const &/* (zyre) group*/ = grp_dft);
				
				// Transmit a message to all nodes.
				virtual zmq::msg const/* message: response*/ broadcast (zmq::msg/* message: request*/, cln::nr &/* responses_count: to be written to*//* number of peers who returned a response*/);
				
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
				virtual zmq::msg const rx_local (std::string const &/* request_token*/, cln::nr const &/* number of expected responses*/, cln::nr &/* responses_count*//* number of peers who actually answered*/, std::string const &/* src*/, net::cast const &/* src_cast*/) const;
				
				// Transmits/Redirect the response to the thread who queried it.
				//virtual const bool unicast_local (const zmq::msg &/* message*/) const;
				virtual bool const unicast_local (zmq::msg const &/* message*/, std::string const &/* request_token*/) const;
				//virtual const bool unicast_local (const zmsg_t */* message*/) const;
				
				static std::string const grp_dft;
				static cln::nr const token_size_dft;
				
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
				
			protected:
				// manage request
				virtual bool const/* success*/ respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
				virtual bool const/* success*/ respond_post (zmq::msg const &/* response (read-only)*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/, bool const &/* result*/);
				//virtual const bool/* success*/ rx_response (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ rx_request (const zyre_event_t */* (zyre) event*/);
				//virtual const bool/* success*/ request (const zyre_event_t */* (zyre) event*/);
			//	virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/);
				//virtual const bool/* success*/ infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/);
				virtual bool const/* success*/ infrastruct (zyre_event_t const * const/* (zyre) event*/, std::string const &/* event_type*/);
				virtual bool const/* success*/ aggregate_local (zmq::msg &/* overall/final result*/, zmq::msg const &/* current response message/expression*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
				virtual bool const/* success*/ aggregate_remote (zmq::msg &/* overall/final result. passed during each iteration*/, zmq::msg const &/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
				virtual zmq::msg const/* result*/ aggregate (zmq::msg const &/* result*/, zmq::msg const &/* response*/, zmq::msg const &/* expression*/, cln::nr const &/* responses_count*//* number of peers who answered*/, std::string const &/* src*/, net::cast const &/* src_cast*/);
				virtual bool const/* success*/ search_local (zmq::msg const &/* overall/final result*/, zmq::msg const &/* current response message/expression*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
				virtual bool const/* success*/ search_remote (zmq::msg const &/* overall/final result. passed during each iteration*/, zmq::msg const &/* current response message/expression*/, cln::nr const &/* total, expected resonses count*/, cln::nr const &/* current count of peers who responded (so far)*/, std::string const &/* src*/, net::cast const &/* src_cast*/);// const
				
				/*
					architectural overview
					
					{
						*val()
						{
							zmq::msg result;
							
							 aggregate_local (&result);
							if (search_local ( result))
								return result;
							else
								return aggregate
								{
									return [2nd argument] (by default);
								}
								(
									result,
									*cast
									{
										return rx_local
										{
											zmq::msg final_result;
											zmq::msg current_response;
											
											foreach (response)
											{
												current_response = zmq::recv ();
												
												aggregate_remote (&final_result, current_response);
												   search_remote ( final_result, current_response);
											}
											return final_result;
										} ();
									} ()
								);
						}
					}
				*/
		};
	}
}
