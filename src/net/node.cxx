#pragma once

#include "node.hxx"
//#include "../var.cxx"
//#include "../net/node.cxx"
#include "cast.cxx"
#include <string>
#include <zmq/msg.cxx>
//#include <zyre.h>
#include <zyre.cxx>
#include <noware/random/string.cxx>
#include <cln/nr.cxx>

std::string const noware::net::node::grp_dft = "noware::net::node";
cln::nr const noware::net::node::token_size_dft = 16;

noware::net::node::node (void)
{
	//local_context = new zmq::context_t (1);
	//local_socket = new zmq::socket_t (*local_context, ZMQ_);
	//
	//local_socket -> bind ("");
	
	//init ();
	
	//assert (_node.init ());
	//assert (_node.join (grp_dft));
	
	//_nodes.add (_node);
	
	assert (_node.rx_set (boost::bind (boost::mem_fn (&noware::net::node::rx), this, _1)));
	//	return false;
}

noware::net::node::~node (void)
{
	//_node.stop ();
	//_node.finalize ();
	
	//_nodes.remove (_node);
	//assert (_node.fin ());
	
	//stop ();
	fin ();
	assert (_node.rx_unset ());
}

const bool noware::net::node::fin (void)
{
	//if (!_node.reception_unset ())
	//	return false;
	
	if (!_node.fin ())
		return false;
	
	return true;
}

const bool noware::net::node::inited (void) const
{
	//if (!_node.reception_is_set ())
	//	return false;
	
	if (!_node.inited ())
		return false;
	
	return true;
}

const bool noware::net::node::init (void)
{
	//if (!_node.reception_set (boost::bind (boost::mem_fn (&noware::net::node::rx), this, _1)))
	//	return false;
	
	if (!_node.init ())
		return false;
	
	return true;
}

const bool noware::net::node::stop (void)
{
//	if (!running ())
//		return true;
	
	if (!_node.stop ())
		return false;
	
	//if (!_node.fin ())
	//	return false;
	
	//if (!_node.reception_unset ())
	//	return false;
	
	return true;
}

const bool noware::net::node::running (void) const
{
//	if (!inited ())
//		return false;
	
	if (!_node.running ())
		return false;
	
	//if (!_node.reception_is_set ())
	//	return false;
	
	//if (!_node.inited ())
	//	return false;
	
	return true;
}

const bool noware::net::node::start (void)
{
	//local_context = new zmq::context_t (1);
	//local_socket = new zmq::socket_t (*local_context, ZMQ_);
	//
	//local_socket -> bind ("");
	
//	if (running ())
//		return true;
	
	//if (!_node.init ())
	//	return false;
	
	//if (!_node.start ())
	//	return false;
	
	//if (_node.reception_is_set ())
	//	return true;
	
	//if (!_node.reception_set (boost::bind (boost::mem_fn (&noware::net::node::rx), this, _1)))
	//	return false;
	
	//if (!inited ())
	//	return false;
	
	if (!enabled ())
		return false;
	
	if (!_node.start ())
		return false;
	
	//_nodes.add (_node);
	
	return true;
}

const bool noware::net::node::disable (void)
{
	if (!_node.stop ())
		return false;
	
	return false;
}

const bool noware::net::node::enabled (void) const
{
	return true;
}

const bool noware::net::node::enable (void)
{
	return true;
}

const zmq::msg/* value*/ noware::net::node::locval (const zmq::msg & expression)
{
	return unival (expression, _node.id ());
}

const zmq::msg/* value*/ noware::net::node::unival (const zmq::msg & expression, const std::string & peer_id)
{
	zmq::msg result;
	
	if (search_local (result, expression, peer_id, net::cast::uni))
		return result;
	else
	{
		//cln::nr responses_count;
		
		return aggregate (result, unicast (expression, peer_id), expression, 1, peer_id, net::cast::uni);
	}
}

const zmq::msg/* value*/ noware::net::node::anyval (const zmq::msg & expression)
{
	zmq::msg result;
	std::string peer_id;
	
	peer_id = _node.any ();
	
	std::cerr << " noware::net::node::anyval()::peer.id::[" << peer_id << "]" << std::endl;
	
	if (search_local (result, expression, peer_id, net::cast::uni))
		return result;
	else
	{
		//cln::nr responses_count;
		//std::string peer_id;
		
		//return aggregate (result, anycast (expression, peer_id), expression, 1, peer_id);
		return aggregate (result, unicast (expression, peer_id), expression, 1, peer_id, net::cast::uni);
	}
}

const zmq::msg/* value*/ noware::net::node::anyval (const zmq::msg & expression, const std::string & group)
{
	zmq::msg result;
	std::string peer_id;
	
	peer_id = _node.any (group);
	
	std::cerr << " noware::net::node::anyval(group)::peer.id::[" << peer_id << "]" << std::endl;
	
	if (search_local (result, expression, peer_id, net::cast::uni))
		return result;
	else
	{
		//cln::nr responses_count;
		
		//return aggregate (result, anycast (expression, /*noware::net::node::*/group), expression, 1, group);
		return aggregate (result, unicast (expression, /*noware::net::node::*/peer_id), expression, 1, peer_id, net::cast::uni);
	}
}

zmq::msg const noware::net::node::multival (const zmq::msg & expression, const std::string & group)
{
	zmq::msg result;
	
	if (search_local (result, expression, group, net::cast::multi))
		return result;
	else
	{
		cln::nr responses_count;
		
		return aggregate (result, multicast (expression, responses_count, /*noware::net::node::*/group), expression, responses_count, group, net::cast::multi);
	}
	
	//return "";
	//if (!_nodes.val (expression))
	//	return false;
	//_nodes.val (expression);
	//
	//return _nodes.respond ();
}

zmq::msg const/* value*/ noware::net::node::broadval (const zmq::msg & expression)
{
	zmq::msg result;
	
	if (search_local (result, expression, "", net::cast::broad))
		return result;
	else
	{
		cln::nr responses_count;
		
		return aggregate (result, broadcast (expression, responses_count), expression, responses_count, "", net::cast::broad);
	}
}

zmq::msg const noware::net::node::aggregate (const zmq::msg &/* result*//* from search_local*/, const zmq::msg & response/* from ...search*/, const zmq::msg &/* expression*/, const cln::nr &/* responses_count*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
{
	return response;
}

zmq::msg const noware::net::node::unicast (zmq::msg msg_req, /*const std::string & filter, */std::string const & peer)
{
	std::cerr << "noware::net::node::unicast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_resp;
	cln::nr responses_count;
	
	//return msg_resp;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::net::node::unicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (noware::net::node::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	//msg_req.prepend (zmq::msg::frame ("noware::net::node::response"));
	
	if (!_node.unicast (/*filter + */msg_req, peer))
	{
		std::cerr << "noware::net::node::unicast()::_node.unicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::net::node::unicast()::_node.unicast()::success" << std::endl;
	//return rx_local (message ["subject"].get_value (), filter);
	//return rx_local (message, filter);
	
	//return msg_resp;
	return rx_local (request_token, 1, responses_count, peer, net::cast::uni);
	//return rx_local_uni (peer, filter);
}

const zmq::msg/* message: response*/ noware::net::node::anycast (zmq::msg msg_req, std::string & peer_id)
{
	std::cerr << "noware::net::node::anycast()::called" << std::endl;
	
	std::string request_token;
	//std::string peer_id;
	zmq::msg msg_response;
	cln::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::net::node::anycast(msg)::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (noware::net::node::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!_node.anycast (msg_req, peer_id))
	{
		std::cerr << "noware::net::node::anycast()::_node.anycast()::failure" << std::endl;
		return msg_response;
	}
	
	//return rx_local (request_token, 1, responses_count, grp_dft);
	return rx_local (request_token, 1, responses_count, peer_id, net::cast::uni);
}

const zmq::msg/* message: response*/ noware::net::node::anycast (zmq::msg msg_req, std::string & peer_id, const std::string & group)
{
	std::cerr << "noware::net::node::anycast(" << group << ")::called" << std::endl;
	
	std::string request_token;
	//std::string peer_id;
	zmq::msg msg_response;
	cln::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::net::node::anycast(msg," << group << ")::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (noware::net::node::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	std::cerr << "noware::net::node::anycast(" << group << ")::msg_req.data::pre-loop" << std::endl;
	for (const std::pair <unsigned int, zmq::msg::frame> & element : msg_req.data)
	{
		std::cerr << "noware::net::node::anycast(" << group << ")::msg_req.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
	}
	
	std::cerr << "noware::net::node::anycast(" << group << ")::_node.anycast(" << group << ")::pre" << std::endl;
	if (!_node.anycast (msg_req, peer_id, group))
	{
		std::cerr << "noware::net::node::anycast(" << group << ")::_node.anycast(" << group << ")::failure" << std::endl;
		return msg_response;
	}
	std::cerr << "noware::net::node::anycast(" << group << ")::_node.anycast(" << group << ")::success" << std::endl;
	
	//return rx_local (grp_dft, responses_count, request_token, 1);
	return rx_local (request_token, 1, responses_count, peer_id, net::cast::uni);
}

const zmq::msg noware::net::node::multicast (zmq::msg msg_req, cln::nr & responses_count, const std::string & group)
{
	std::cerr << "noware::net::node::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	std::string request_token;
	zmq::msg msg_resp;
	//cln::nr responses_count;
	
//	std::string filter;
	
//	filter = "";
//	filter += (noware::var) '/' + "response";
	
	//if (message.exists ("subject"))
//		filter += (noware::var) '/' + message ["subject"];
	
	//filter += (noware::var) '/' + message ["type"];
	
	//if (message.exists ("name"))
//		filter += (noware::var) '/' + message ["name"];
	
	//if (message.exists ("content"))
	//	filter += '/' + message ["content"];
	
	// Data, collapsed into a string.
	//message ["filter"] = filter;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::net::node::multicast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (noware::net::node::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!_node.multicast (/*filter + */msg_req, group))
	{
		std::cerr << "noware::net::node::multicast()::_node.multicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cerr << "noware::net::node::multicast()::_node.multicast()::success" << std::endl;
	//return rx_local (message ["subject"].get_value (), filter);
	//return rx_local (message, filter);
	//return rx_local (responses_count, request_token, group);
	//return rx_local (grp_dft, responses_count, request_token, _node.peers_size (group));
	return rx_local (request_token, _node.peer_size (group), responses_count, group, net::cast::multi);
	
	/*
	// Prepare for reception.
	zmq::context_t context (1);
	zmq::socket_t receiver (context, ZMQ_SUB);
	receiver.connect ("tcp://127.0.0.1:5555");
	
	// Subscribe only to the answer we asked for.
	receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), filter.length ());
	
	noware::tree <> response;
	//std::stringstream ss;
	zmq::message_t response_zmq;
	for (;;)
	{
		receiver.recv (&response_zmq);
		//ss << static_cast <char *> (response_zmq.data ());
		// Parse the message into a tree object.
		//response.deserialize (ss.to_string ());
		//response.deserialize (static_cast <char *> (response_zmq.data ()));
		//if ()
		//ss.clear ();
	}
	*/
}

const zmq::msg/* message: response*/ noware::net::node::broadcast (zmq::msg msg_req, cln::nr & responses_count/* number of peers who answered*/)
{
	std::cerr << "noware::net::node::broadcast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_response;
	//cln::nr responses_count;
	
	request_token = noware::random::string (token_size_dft);
	std::cerr << "noware::net::node::broadast()::request_token==[" << request_token << ']' << std::endl;
	
	msg_req.prepend (zmq::msg::frame (noware::net::node::grp_dft + std::string ("::response::desired")));
	msg_req.prepend (zmq::msg::frame (request_token));
	
	if (!_node.broadcast (msg_req))
	{
		std::cerr << "noware::net::node::multicast()::_node.multicast()::failure" << std::endl;
		return msg_response;
	}
	
	//return rx_local (grp_dft, responses_count, request_token, _node.peers_size ());
	return rx_local (request_token, _node.peer_size (), responses_count, "", net::cast::broad);
}

void noware::net::node::rx (zyre_event_t * const event)
{
	std::cerr << "noware::net::node::receive()::called" << std::endl;
	
	if (event == nullptr)
	{
		std::cerr << "noware::net::node::receive()::event==nullptr" << std::endl;
		std::cerr << "noware::net::node::receive()::return" << std::endl;
		
		return;
	}
	
	//const char * event_type = zyre_event_type (event);
	std::string event_type;
	std::string src;
	net::cast src_cast;
	//noware::tree <> message_zyre;
	//noware::tree <> message;
	//zmsg_t * zmsg;
	//zframe_t * zframe;
	zmq::msg msg;
	//cln::nr frame_ndx;
	bool result;
	//bool respond;
	
	event_type = zyre_event_type (event);
	//src = zyre_event_group (event);
	
	//if (event_type == "WHISPER" || event_type == "SHOUT")
	//{
		
		//zmsg_t * zmq_msg;
		
		//if (zmq_msg != nullptr)
		//{
		//	std::cerr << "noware::net::node::receive()::zmq_msg!=nullptr" << std::endl;
			//std::string msg;
			//noware::tree <> msg;
			
			// First, get the message from the zyre peer.
			//zmsg = zyre_event_msg (event);
			/*
			frame_ndx = 1;
			zframe = zmsg_first (zmsg);
			
			while (zframe != nullptr)
			{
				msg.data [frame_ndx] = *zframe;
				zframe = zmsg_next (zmsg);
				++frame_ndx;
			}
			*/
			
			//if (msg.deserialize (zmsg_popstr (zmq_msg)))
			//{
				//std::cerr << "*zmq_msg==" << '[' << (const char *) zmq_msg << ']' << std::endl;
				//std::cerr << "zmsg_popstr(zmq_msg)==" << '[' << zmsg_popstr (zmq_msg) << ']' << std::endl;
			//	std::cerr << "msg.serialize()==" << '[' << msg.serialize () << ']' << std::endl;
				
				
	//bool result;
	
	//zmq::msg msg;
	zmsg_t * zmsg;
	//zmsg_t * zmsg_response;
	//zframe_t * zframe_response;
	//std::string event_type;
	//std::string response_token;
	std::string request_token;
	
	//zmsg = zyre_event_msg (event);
	//msg = zyre_event_msg (event);
	//msg = zmsg;
	//event_type = zyre_event_type (event);
	//assert (event);
	//assert (zmsg);
	
	//event_type = zyre_event_type (event);
	
	std::cerr << "noware::net::node::receive()::event_type==[" << event_type << ']' << std::endl;
	
	//result = _node.unicast (respond (msg), zyre_event_peer_uuid (event));
//	std::cerr << "noware::net::node::receive()::responding()..." << std::endl;
	//result = respond (zmsg, event);
//	result = respond (event);
//	std::cerr << "noware::net::node::receive()::responded()==" << '[' << (result ? "success" : "failure") << ']' << std::endl;
	//std::cerr << "noware::net::node::receive()::_node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
	
	// request
	// response
	// data message
	// WHISPER SHOUT
	if (event_type == "WHISPER" || event_type == "SHOUT")
	{
		std::cerr << "noware::net::node::receive()::event_type==(WHISPER||SHOUT)==[" << event_type << ']' << "::in scope" << std::endl;
		//std::cerr << "noware::net::node::respond()::event not of interest" << std::endl;
		
		//return false;
		zmsg = zyre_event_msg (event);
		
		if (zmsg != nullptr)
		{
			std::cerr << "noware::net::node::receive()::event_msg==nullptr" << std::endl;
			
			if (event_type == "WHISPER")
			{
				src_cast = net::cast::uni;
				src = zyre_event_peer_uuid (event);
			}
			else //if (event_type = "SHOUT")
			{
				src_cast = net::cast::multi;
				src = zyre_event_group (event);
			}
			
			//return false;
			//respond = false;
			
			std::cerr << "noware::net::node::receive()::event of type data" << std::endl;
			msg = zmsg;
			
			//response_token = msg.first ();
			
			std::cerr << "noware::net::node::receive()::msg.data::pre-loop" << std::endl;
			for (const std::pair <unsigned int, zmq::msg::frame> & element : msg.data)
			{
				std::cerr << "noware::net::node::receive()::msg.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
			}
			
			request_token = msg.first ();
			msg.first_rm ();
			
			std::cerr << "noware::net::node::receive()::request_token::post-removal" << std::endl;
			
			std::cerr << "noware::net::node::receive()::msg.data::pre-loop" << std::endl;
			for (const std::pair <unsigned int, zmq::msg::frame> & element : msg.data)
			{
				std::cerr << "noware::net::node::receive()::msg.data[" << element.first << "]==\"" << std::string (element.second) << "\"" << std::endl;
			}
			
			// This message is a response.
			//if (response_token == "noware::net::node::response")
			if (msg.first ()/* response_token*/ == noware::net::node::grp_dft + std::string ("::response::voila"))
			{
				std::cerr << "noware::net::node::receive()::response[" << noware::net::node::grp_dft << "::response::voila]" << std::endl;
				
				msg.first_rm ();
				
				
				std::cerr << "noware::net::node::receive()::unicast_local(msg," << request_token << ")" << std::endl;
				// Redirect the message to the function which asked for it.
				////unicast_local (zmsg_popstr (zmq_msg));
				//result = unicast_local (msg_rx);
				result = unicast_local (msg, request_token);
				std::cerr << "noware::net::node::receive()::unicast_local(msg," << request_token << ")==[" << (result ? "success" : "failure") << "]" << std::endl;
				
				//return result;
			}
			// This message is a request;
			// a response (confirmation) is also being requested.
			else if (msg.first ()/* response_token*/ == noware::net::node::grp_dft + std::string ("::response::desired"))
			{
				std::cerr << "noware::net::node::receive()::request[" << noware::net::node::grp_dft << "::response::desired]" << std::endl;
				
				msg.first_rm ();
				
				zmq::msg msg_response;
				
				result = respond (msg_response, msg, event, event_type, src, src_cast);
				
				if (result)
				{
					std::cerr << "noware::net::node::receive()::respond[true]" << std::endl;
					
					msg_response.prepend (zmq::msg::frame (noware::net::node::grp_dft + std::string ("::response::voila")));
					msg_response.prepend (zmq::msg::frame (request_token));
					
					// Send back the answer/confirmation.
					result = _node.unicast (msg_response, zyre_event_peer_uuid (event));
					
					//if (result)
					//{
						std::cerr << "noware::net::node::receive()::responded::result[" << result << "]" << std::endl;
						
						std::cerr << "noware::net::node::receive()::respond_post'ing" << std::endl;
						
						result = respond_post (msg_response, msg, event, event_type, src, src_cast, result);
						
						std::cerr << "noware::net::node::receive()::respond_post'ed::result[" << result << "]" << std::endl;
					//}
				}
				else
				{
					std::cerr << "noware::net::node::receive()::respond[false]" << std::endl;
				}
			}
			// This message is a request;
			// a response is not being requested.
			else
			{
				std::cerr << "noware::net::node::receive()::request[" << noware::net::node::grp_dft << "::response::nondesired]" << std::endl;
				
				if (msg.first () == noware::net::node::grp_dft + std::string ("::response::nondesired"))
					msg.first_rm ();
				
				zmq::msg msg_response;
				
				result = respond (msg_response, msg, event, event_type, src, src_cast);
			}
		}
	}
	// infrastructure message
	// ENTER EXIT JOIN LEAVE
	else
	{
		std::cerr << "noware::net::node::receive()::event of type infrastruct[ure]" << std::endl;
		result = infrastruct (/*msg, */event, event_type/*, src, src_cast*/);
		std::cerr << "noware::net::node::receive()::infrastruct(event," << event_type << ",msg)==[" << (result ? "success" : "failure") << "]" << std::endl;
	}
	
	//std::cerr << "noware::net::node::receive()::event==" << event_type << std::endl;
	
				
				
			//}
			//else
			//{
			//	std::cerr << "noware::net::node::receive()::msg.deserialize()==False" << std::endl;
			//}
			//std::cerr << "noware::net::node::receive()::msg[subject]==[" << msg ["subject"] << ']' << std::endl;
		//}
		//else
		//{
		//	std::cerr << "noware::net::node::receive()::zmq_msg==nullptr" << std::endl;
		//}
	//}
	
	//std::cerr << "noware::net::node::receive()::free()..." << std::endl;
	////free (event_type);
	//std::cerr << "noware::net::node::receive()::free()...OK" << std::endl;
	std::cerr << "noware::net::node::receive()::result[" << (result ? "true" : "false") << "]" << std::endl;
	
	//return result;
}

//const bool noware::net::node::respond (const zmsg_t */* msg*/, const zyre_event_t */* event*/)
bool const noware::net::node::respond (zmq::msg &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, net::cast const &/* src_cast*/)
{
	std::cerr << "noware::net::node::respond()::called" << std::endl;
	
	return false;
}

bool const noware::net::node::respond_post (zmq::msg const &/* response*/, zmq::msg const &/* rx'd*/, zyre_event_t const * const/* event*/, std::string const &/* event_type*/, std::string const &/* src*/, const net::cast &/* src_cast*/, bool const & result)
{
	std::cerr << "noware::net::node::respond_post()::called" << std::endl;
	
	return true;
}

//const bool noware::net::node::infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* event*/, const std::string &/* event_type*/, const std::string &/* src*/, const net::cast &/* src_cast*/)
//const bool noware::net::node::infrastruct (const zmq::msg &/* rx'd*/, const zyre_event_t */* event*/, const std::string &/* event_type*/)
const bool noware::net::node::infrastruct (const zyre_event_t */* event*/, const std::string &/* event_type*/)
{
	std::cerr << "noware::net::node::infrastruct()::called" << std::endl;
	
	return false;
}

const zmq::msg noware::net::node::rx_local (const std::string & request_token/*, const std::string & response_type*/, const cln::nr & responses_expected, cln::nr & responses_count, const std::string & src, const net::cast & src_cast) const
{
	std::cerr << "noware::net::node::rx_local::called" << std::endl;
	//std::cerr << "noware::net::node::rx_local(response_type=[" << response_type << "], filter=[" << filter << "])::called" << std::endl;
	
	int bind_return_code;
	
	// Socket options.
	//int linger;
	//int recv_timeout;
	
	std::string conn;	// Connection string.
	
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cerr << "noware::net::node::rx_local()::conn==[" << conn << ']' << std::endl;
	std::cerr << "noware::net::node::rx_local()::request_token==[" << request_token << ']' << std::endl;
	
	zmq::context_t context (1);
	//  Socket to talk to server
	//std::cerr << "Collecting updates from weather server...\n" << std::endl;
	//zmq::socket_t receiver (context, ZMQ_SUB);
	//zmq::socket_t receiver (context, ZMQ_PAIR);
	//zmq::socket_t receiver (context, ZMQ_REP);
	//zmq::socket_t receiver (context, ZMQ_DEALER);
	zmq::socket_t receiver (context, ZMQ_PULL);
	//receiver.bind ("tcp://127.0.0.1:3210");
	//receiver.bind (conn.c_str ());
	//receiver.bind ("tcp://0.0.0.0:5555");
	receiver.bind ((std::string ("ipc://./") + request_token).c_str ());
	//receiver.bind ((std::string ("inproc://") + request_token).c_str ());
	//receiver.bind ((std::string ("inproc://test")).c_str ());
	
	//std::cerr << "noware::net::node::rx_local()::receiver.bind()==[" << bind_return_code << ']' << std::endl;
	//linger = 0;	// No lingering...
	//recv_timeout = 3000;	// 3 seconds
	
	// Subscribe to the filter.
	//receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), sizeof (filter));
	//receiver.setsockopt (ZMQ_LINGER, &linger, sizeof (linger));
	receiver.setsockopt <int> (ZMQ_LINGER, 0);
	//receiver.setsockopt (ZMQ_RCVTIMEO, &recv_timeout, sizeof (recv_timeout));
	receiver.setsockopt <int> (ZMQ_RCVTIMEO, 3000/* ms*/);
	
	
	// zlist_t * peers;
	
	//assert (zlist_size (peers) == 1);
	//zlist_destroy (&peers);
	
	zmq::msg message;
	zmq::msg response;
	zmq::msg response_tmp;
	//cln::nr::natural n;
	//zmq::message_t message_filter;
	zmq::message_t message_content;
	//boost::function <const bool/* search_* */ (const noware::tree <> &/* response_type*/, noware::var &/* filter*/)> search;
	
	/*
	response = "";
	// Decide which search function should be used.
	std::cerr << "noware::net::node::rx_local(response_type=[" << response_type << "], filter=[" << filter << "])::pre-if" << std::endl;
	if (response_type == "get")
	{
	  std::cerr << "noware::net::node::rx_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::net::node::search_get), this, _1, _2);
		//search = &noware::net::node::search_get;
	}
	else if (response_type == "set")
	{
	  std::cerr << "noware::net::node::rx_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::net::node::search_set), this, _1, _2);
		//search = &noware::net::node::search_set;
	}
	else
	{
	  std::cerr << "noware::net::node::rx_local()::response_type::if-else::in scope" << std::endl;
		return "";
	}
	*/
	
	//std::cerr << "noware::net::node::rx_local(response_type=[" << response_type << "], filter=[" << filter << "])::_node.size()==[" << _node.size () << ']' << std::endl;
	//std::cerr << "noware::net::node::rx_local(filter=[" << filter << "])::_node.size()==[" << _node.size () << ']' << std::endl;
	std::cerr << "noware::net::node::rx_local::_node.peers_size()==[" << _node.peer_size () << ']' << std::endl;
	
	/*
	//zlist_t * peers;
	peers = zyre_peers (_node.zyre ());
	if (peers == nullptr);
	{
		std::cerr << "noware::net::node::rx_local(response_type=[" << response_type << "], filter=[" << filter << "])::peers==nullptr" << std::endl;
		
		return result;
	}
	*/
	// Ensure that all relevant peers respond.
	//n = 0;
	//result = "";
	unsigned int responses_nr;
	unsigned int responses_expect;
	
	//responses_nr = responses_count;
	responses_expect = responses_expected;
  std::cerr << "noware::net::node::rx_local()::pre-loop" << std::endl;
	std::cerr << "noware::net::node::rx_local()::responses_expected==[" << responses_expected << ']' << std::endl;
	std::cerr << "noware::net::node::rx_local()::responses_expect==[" << responses_expect << ']' << std::endl;
	//std::cerr << "noware::net::node::rx_local()::responses_count==[" << responses_count << ']' << std::endl;
	//std::cerr << "noware::net::node::rx_local()::responses_nr==[" << responses_nr << ']' << std::endl;
	//for (/*cln::nr::natural n*/responses_count = 0; responses_count < /*zlist_size (peers)*/ cln::nr (_node.size (group)); ++responses_count)
	//for (/*cln::nr::natural n*/responses_nr = 0; responses_nr < /*zlist_size (peers)*/ _node.size (group); ++responses_nr)
	for (/*cln::nr::natural n*/responses_nr = 0; responses_nr < /*zlist_size (peers)*/ responses_expect; ++responses_nr)
	{
		//std::cerr << "noware::net::node::rx_local()::while::responses_count==[" << responses_count << ']' << std::endl;
		std::cerr << "noware::net::node::rx_local()::while::index/responses occured so far==[" << responses_nr << ']' << std::endl;
		
		//zmq::message_t message_filter;
		//zmq::message_t message_content;
		
		//std::cerr << "noware::net::node::rx_local()::loop::receiving::filter" << std::endl;
		//receiver.recv (&message_filter);
		//std::cerr << "noware::net::node::rx_local()::loop:: received::filter" << std::endl;
		
		std::cerr << "noware::net::node::rx_local()::loop::receiving::message" << std::endl;
		if (!receiver.recv (&message_content))
		{
			//std::cerr << "noware::net::node::rx_local()::loop::receiving::message::[false]" << std::endl;
			std::cerr << "noware::net::node::rx_local()::loop::receiving::message::[false]::break" << std::endl;
			
			break;
		}
		
		std::cerr << "noware::net::node::rx_local()::loop:: received::message" << std::endl;
		
		std::cerr << "noware::net::node::rx_local()::message_tree.deserialize()::pre-call" << std::endl;
		
		//std::cerr << "noware::net::node::rx_local()::message_filter.data()==[" << static_cast <const char *> (message_filter.data ())	<< ']' << std::endl;
		
		std::cerr << "noware::net::node::rx_local()::message_content.data()==[" << static_cast <const char *> (message_content.data ()) << ']' << std::endl;
		
		//message = static_cast <const char *> (message_content.data ());
		message = message_content;
		//if (!message_tree.deserialize (static_cast <const char *> (message_content.data ())))
		//{
		//	std::cerr << "noware::net::node::rx_local()::message_tree.deserialize()==False" << std::endl;
		//	return response;
		//}
		
		std::cerr << "noware::net::node::rx_local()::message_tree.deserialize()==True" << std::endl;
		// Refresh the list of peers,
		// in case any of them departed the cluster since our previous iteration(s),
		// even if it is improbable.
		/*
		zlist_destroy (&peers);
		//zlist_t * peers;
		peers = zyre_peers (_node.zyre ());
		
		if (peers == nullptr)
		{
		  std::cerr << "noware::net::node::rx_local()::in-while::peers==nullptr" << std::endl;
			return "";
		}
		*/
		// React to/Parse the message.
		// search() returns bool/success if we found the (correct) answer that we are searching for.
		// when we haven't yet found the entire answer, we continue;
		// when we fail, we (could) short-circuit the loop (stop looping).
  	std::cerr << "noware::net::node::rx_local()::if(search())::pre-call" << std::endl;
		if (search (response, message, responses_expected/* total count*/, responses_nr/* current count*/, src, src_cast))
		{
	  	//std::cerr << "noware::net::node::rx_local()::if(search())::break" << std::endl;
	  	std::cerr << "noware::net::node::rx_local()::if(search())::found" << std::endl;
			//break;
			//response = response_tmp;
		}
  	std::cerr << "noware::net::node::rx_local()::if(search())::post-call" << std::endl;
		
		//++n;
	}
  std::cerr << "noware::net::node::rx_local()::post-loop" << std::endl;
	
	responses_count = responses_nr;
	//zlist_destroy (&peers);
	
  //std::cerr << "noware::net::node::rx_local()::return response==[" << response << ']' << std::endl;
	return response;
	
	//std::istringstream iss(static_cast<char*>(update.data()));
	//std::cerr << "Message=" << '[' << static_cast <char *> (update.data ()) << ']' << std::endl;
}

bool const noware::net::node::unicast_local (zmq::msg const & msg, std::string const & request_token) const
//const bool noware::net::node::unicast_local (const zmsg_t * msg) const
{
	//zmq::msg filter;
	zmq::message_t message;
	//std::string msg_serial;
	//zframe_t * zframe;
	std::string conn;	// Connection string.
	//noware::tree <> msg_tree;
	bool result;
	
	//filter = "";
	
	//filter += (noware::var) '/' + "response";
	//msg_tree.deserialize (msg);
	
	//if (msg_tree.exists ("subject"))
//		filter += (noware::var) '/' + msg ["subject"];
	
//	filter += (noware::var) '/' + msg ["type"];
	
	//if (msg_tree.exists ("name"))
//		filter += (noware::var) '/' + msg ["name"];
	
	//if (msg_tree.exists ("content"))
	//	filter += '/' + msg_tree ["content"];
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
//	std::cerr << "noware::net::node::unicast_local()::msg[content].get_value ().text ()==[" << msg << ']' << std::endl;
	//std::cerr << "noware::net::node::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	////std::cerr << "noware::net::node::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	
	//zframe = zmsg_first (msg);
	//message.rebuild (zframe_data (zframe), zframe_size (zframe));
	
	
	std::cerr << "noware::net::node::unicast_local()::conn==[" << conn << ']' << std::endl;
	std::cerr << "noware::net::node::unicast_local()::request_token==[" << request_token << ']' << std::endl;
	
	//msg_serial = msg.serialize ();
	
	zmq::context_t context (1);
	//zmq::socket_t transmitter (context, ZMQ_PUB);
	//zmq::socket_t transmitter (context, ZMQ_PAIR);
	//zmq::socket_t transmitter (context, ZMQ_REQ);
	//zmq::socket_t transmitter (context, ZMQ_DEALER);
	zmq::socket_t transmitter (context, ZMQ_PUSH);
	//transmitter.connect ("tcp://127.0.0.1:3210");
	//transmitter.connect (conn.c_str ());
	//transmitter.bind ("tcp://*:5555");
	transmitter.connect ((std::string ("ipc://./") + request_token).c_str ());
	//transmitter.connect ((std::string ("inproc://") + request_token).c_str ());
	//transmitter.connect ((std::string ("inproc://test")).c_str ());
	
	/////zmq::message_t filter_msg (sizeof (filter.c_str ()));
	//zmq::message_t filter_msg (filter.length ());
	////zmq::message_t message (sizeof (msg_serial.c_str ()));
	//zmq::message_t message (msg.length ());

	//snprintf ((char *) message.data(), 20 ,
	//	"%05d %d %d", zipcode, temperature, relhumidity);
	//std::memcpy (filter_msg.data (), filter.c_str (), sizeof (filter.c_str ()));
//	std::memcpy (filter_msg.data (), filter.c_str (), filter.length ());
	//std::memcpy (message.data (), msg_serial.c_str (), sizeof (msg_serial.c_str ()));
//	std::memcpy (message.data (), msg.c_str (), msg.length ());
	
//	std::cerr << "message==" << '[' << static_cast <const char *> (message.data ()) << ']' << std::endl;
	std::cerr << "noware::net::node::unicast_local()::message==" << '[' << static_cast <const char *> (msg.operator zmq::message_t & ().data ()) << ']' << std::endl;
	
	
  std::cerr << "noware::net::node::unicast_local()::send()" << std::endl;
	//return
	result =
		//transmitter.send (filter_msg, ZMQ_SNDMORE)
		//&&
		//transmitter.send (msg.operator zmq::message_t & ())
		//transmitter.send (message);
		transmitter.send (msg.operator zmq::message_t & ()/*, ZMQ_DONTWAIT*/);
	;
	
	//zclock_sleep (1500);
	
	std::cerr << "noware::net::node::unicast_local()::send()[" << (result ? "true" : "false") << ']' << std::endl;
	
	//return true;
	return result;
}

// Short-circuited (triggered by success).
const bool noware::net::node::search (zmq::msg &/* result*/, const zmq::msg &/* message*/, const cln::nr &/* total, expected resonses count*/, const cln::nr &/* current count of peers who responded (so far)*/, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "noware::net::node::search()::called" << std::endl;
	
	return false;
}

const bool noware::net::node::search_local (zmq::msg &/* result*/, const zmq::msg &/* message*/, const std::string &/* src*/, const net::cast &/* src_cast*/)// const
{
	std::cerr << "noware::net::node::search_local()::called" << std::endl;
	
	return false;
}
