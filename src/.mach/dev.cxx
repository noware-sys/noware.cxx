#pragma once

//#include "dev.hdr.cxx"
#include "../var.cxx"
#include "../net/node.cxx"

const std::string noware::mach::dev::grp_dft = "dev";

noware::mach::dev::dev (void)
{
	node.init ();
	node.reception_set (boost::bind (boost::mem_fn (&noware::mach::dev::receive), this, _1));
	node.start ();
	
	//nodes.add (node);
}

noware::mach::dev::~dev (void)
{
	//node.stop ();
	//node.finalize ();
	
	//nodes.remove (node);
}

const zmq::msg/* value*/ noware::mach::dev::unival (const zmq::msg & expression, const std::string & peer_id)
{
	zmq::msg result;
	
	if (search_local (result, expression))
		return result;
	else
	{
		//noware::nr responses_count;
		
		return aggregate (result, 1, unicast (expression, /*noware::mach::dev::*/peer_id), expression);
	}
}

const zmq::msg/* value*/ noware::mach::dev::anyval (const zmq::msg & expression)
{
	zmq::msg result;
	
	if (search_local (result, expression))
		return result;
	else
	{
		//noware::nr responses_count;
		
		return aggregate (result, 1, anycast (expression), expression);
	}
}

const zmq::msg/* value*/ noware::mach::dev::anyval (const zmq::msg & expression, const std::string & group)
{
	zmq::msg result;
	
	if (search_local (result, expression))
		return result;
	else
	{
		//noware::nr responses_count;
		
		return aggregate (result, 1, anycast (expression, /*noware::mach::dev::*/group), expression);
	}
}

const zmq::msg noware::mach::dev::multival (const zmq::msg & expression, const std::string & group)
{
	zmq::msg result;
	
	if (search_local (result, expression))
		return result;
	else
	{
		noware::nr responses_count;
		
		return aggregate (result, responses_count, multicast (expression, responses_count, /*noware::mach::dev::*/group), expression);
	}
	
	//return "";
	//if (!nodes.val (expression))
	//	return false;
	//nodes.val (expression);
	//
	//return nodes.respond ();
}

const zmq::msg/* value*/ noware::mach::dev::broadval (const zmq::msg & expression)
{
	zmq::msg result;
	
	if (search_local (result, expression))
		return result;
	else
	{
		noware::nr responses_count;
		
		return aggregate (result, responses_count, broadcast (expression, responses_count), expression);
	}
}

const zmq::msg noware::mach::dev::aggregate (const zmq::msg & result/* from search_local*/, const noware::nr & responses_count, const zmq::msg & response/* from ...search*/, const zmq::msg & expression)
{
	return response;
}

const zmq::msg noware::mach::dev::unicast (const zmq::msg & msg_req, /*const std::string & filter, */const std::string & peer)
{
	std::cout << "noware::mach::dev::unicast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_resp;
	noware::nr responses_count;
	
	//return msg_resp;
	
	if (!node.unicast (/*filter + */msg_req, peer))
	{
		std::cout << "noware::mach::dev::unicast()::node.unicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cout << "noware::mach::dev::unicast()::node.unicast()::success" << std::endl;
	//return receive_local (message ["subject"].get_value (), filter);
	//return receive_local (message, filter);
	
	//return msg_resp;
	return receive_local (responses_count, request_token, 1);
	//return receive_local_uni (peer, filter);
}

const zmq::msg/* message: response*/ noware::mach::dev::anycast (const zmq::msg & msg_req)
{
	std::cout << "noware::mach::dev::anycast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_response;
	noware::nr responses_count;
	
	if (!node.anycast (msg_req))
	{
		std::cout << "noware::mach::dev::anycast()::node.anycast()::failure" << std::endl;
		return msg_response;
	}
	
	return receive_local (responses_count, request_token, 1);
}

const zmq::msg/* message: response*/ noware::mach::dev::anycast (const zmq::msg & msg_req, const std::string & group)
{
	std::cout << "noware::mach::dev::anycast(" << group << ")::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_response;
	noware::nr responses_count;
	
	std::cout << "noware::mach::dev::anycast(" << group << ")::node.anycast(" << group << ")::pre" << std::endl;
	if (!node.anycast (msg_req, group))
	{
		std::cout << "noware::mach::dev::anycast(" << group << ")::node.anycast(" << group << ")::failure" << std::endl;
		return msg_response;
	}
	std::cout << "noware::mach::dev::anycast(" << group << ")::node.anycast(" << group << ")::success" << std::endl;
	
	return receive_local (responses_count, request_token, 1);
}

const zmq::msg noware::mach::dev::multicast (const zmq::msg & msg_req, noware::nr & responses_count, const std::string & group)
{
	std::cout << "noware::mach::dev::multicast()::called" << std::endl;
	//if (!message.is_group ())
	//	return "";
	
	std::string request_token;
	zmq::msg msg_resp;
	//noware::nr responses_count;
	
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
	
	if (!node.multicast (/*filter + */msg_req, group))
	{
		std::cout << "noware::mach::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_resp;
	}
	
	std::cout << "noware::mach::dev::multicast()::node.multicast()::success" << std::endl;
	//return receive_local (message ["subject"].get_value (), filter);
	//return receive_local (message, filter);
	//return receive_local (responses_count, request_token, group);
	return receive_local (responses_count, request_token, node.peers_size (group));
	
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

const zmq::msg/* message: response*/ noware::mach::dev::broadcast (const zmq::msg & msg_req, noware::nr & responses_count/* number of peers who answered*/)
{
	std::cout << "noware::mach::dev::broadcast()::called" << std::endl;
	
	std::string request_token;
	zmq::msg msg_response;
	//noware::nr responses_count;
	
	if (!node.broadcast (msg_req))
	{
		std::cout << "noware::mach::dev::multicast()::node.multicast()::failure" << std::endl;
		return msg_response;
	}
	
	return receive_local (responses_count, request_token, node.peers_size ());
}

void noware::mach::dev::receive (const zyre_event_t * event)
{
	std::cout << "noware::mach::dev::receive()::called" << std::endl;
	
	//const char * event_type = zyre_event_type (event);
	std::string event_type = zyre_event_type (event);
	//noware::tree <> message_zyre;
	//noware::tree <> message;
	//zmsg_t * zmsg;
	//zframe_t * zframe;
	zmq::msg msg;
	noware::nr frame_ndx;
	bool result;
	
	std::cout << "noware::mach::dev::receive()::event_type==[" << event_type << ']' << std::endl;
	
	//if (event_type == "WHISPER" || event_type == "SHOUT")
	//{
		std::cout << "noware::mach::dev::receive()::event_type==(WHISPER||SHOUT)==[" << event_type << ']' << "::in scope" << std::endl;
		
		//zmsg_t * zmq_msg;
		
		//if (zmq_msg != nullptr)
		//{
		//	std::cout << "noware::mach::dev::receive()::zmq_msg!=nullptr" << std::endl;
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
				//std::cout << "*zmq_msg==" << '[' << (const char *) zmq_msg << ']' << std::endl;
				//std::cout << "zmsg_popstr(zmq_msg)==" << '[' << zmsg_popstr (zmq_msg) << ']' << std::endl;
			//	std::cout << "msg.serialize()==" << '[' << msg.serialize () << ']' << std::endl;
				
				
				//bool result;
				
				//result = node.unicast (respond (msg), zyre_event_peer_uuid (event));
				std::cout << "noware::mach::dev::receive()::responding()..." << std::endl;
				//result = respond (zmsg, event);
				result = respond (event);
				std::cout << "noware::mach::dev::receive()::responded()==" << '[' << (result ? "success" : "failure") << ']' << std::endl;
				//std::cout << "noware::mach::dev::receive()::node.unicast (response, zyre_event_peer_uuid (event)==" << (result ? "Success" : "Failure") << std::endl;
				
			//}
			//else
			//{
			//	std::cout << "noware::mach::dev::receive()::msg.deserialize()==False" << std::endl;
			//}
			//std::cout << "noware::mach::dev::receive()::msg[subject]==[" << msg ["subject"] << ']' << std::endl;
		//}
		//else
		//{
		//	std::cout << "noware::mach::dev::receive()::zmq_msg==nullptr" << std::endl;
		//}
	//}
	
	//std::cout << "noware::mach::dev::receive()::free()..." << std::endl;
	////free (event_type);
	//std::cout << "noware::mach::dev::receive()::free()...OK" << std::endl;
	std::cout << "noware::mach::dev::receive()::return" << std::endl;
}

//const bool noware::mach::dev::respond (const zmsg_t */* msg*/, const zyre_event_t */* event*/)
const bool noware::mach::dev::respond (const zyre_event_t */* event*/)
{
	std::cout << "noware::mach::dev::respond()::called" << std::endl;
	
	return false;
}

const zmq::msg noware::mach::dev::receive_local (noware::nr & responses_count, const std::string & request_token/*, const std::string & response_type*/, const noware::nr & responses_expected) const
{
	std::cout << "noware::mach::dev::receive_local::called" << std::endl;
	//std::cout << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::called" << std::endl;
	
	int bind_return_code;
	
	std::string conn;	// Connection string.
	
	//conn = (std::string) "inproc://" + filter;
	//conn = "inproc://connection1";
	
	std::cout << "noware::mach::dev::receive_local()::conn==[" << conn << ']' << std::endl;
	
	zmq::context_t context (1);
	//  Socket to talk to server
	//std::cout << "Collecting updates from weather server...\n" << std::endl;
	//zmq::socket_t receiver (context, ZMQ_SUB);
	//zmq::socket_t receiver (context, ZMQ_PAIR);
	zmq::socket_t receiver (context, ZMQ_REP);
	receiver.bind ("tcp://127.0.0.1:3210");
	//receiver.bind (conn.c_str ());
	//receiver.bind ("tcp://0.0.0.0:5555");
	
	//std::cout << "noware::mach::dev::receive_local()::receiver.bind()==[" << bind_return_code << ']' << std::endl;
	
	
	// Subscribe to the filter.
	//receiver.setsockopt (ZMQ_SUBSCRIBE, filter.c_str (), sizeof (filter));
	
	
	// zlist_t * peers;
	
	//assert (zlist_size (peers) == 1);
	//zlist_destroy (&peers);
	
	zmq::msg message;
	zmq::msg response;
	//noware::nr::natural n;
	//zmq::message_t message_filter;
	zmq::message_t message_content;
	//boost::function <const bool/* search_* */ (const noware::tree <> &/* response_type*/, noware::var &/* filter*/)> search;
	
	/*
	response = "";
	// Decide which search function should be used.
	std::cout << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::pre-if" << std::endl;
	if (response_type == "get")
	{
	  std::cout << "noware::mach::dev::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::mach::dev::search_get), this, _1, _2);
		//search = &noware::mach::dev::search_get;
	}
	else if (response_type == "set")
	{
	  std::cout << "noware::mach::dev::receive_local()::response_type==[" << response_type << ']' << "::in scope" << std::endl;
		search = boost::bind (boost::mem_fn (&noware::mach::dev::search_set), this, _1, _2);
		//search = &noware::mach::dev::search_set;
	}
	else
	{
	  std::cout << "noware::mach::dev::receive_local()::response_type::if-else::in scope" << std::endl;
		return "";
	}
	*/
	
	//std::cout << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::node.size()==[" << node.size () << ']' << std::endl;
	//std::cout << "noware::mach::dev::receive_local(filter=[" << filter << "])::node.size()==[" << node.size () << ']' << std::endl;
	std::cout << "noware::mach::dev::receive_local::node.peers_size()==[" << node.peers_size () << ']' << std::endl;
	
	/*
	//zlist_t * peers;
	peers = zyre_peers (node.zyre ());
	if (peers == nullptr);
	{
		std::cout << "noware::mach::dev::receive_local(response_type=[" << response_type << "], filter=[" << filter << "])::peers==nullptr" << std::endl;
		
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
  std::cout << "noware::mach::dev::receive_local()::pre-loop" << std::endl;
	std::cout << "noware::mach::dev::receive_local()::responses_expected==[" << responses_expected << ']' << std::endl;
	std::cout << "noware::mach::dev::receive_local()::responses_expect==[" << responses_expect << ']' << std::endl;
	//std::cout << "noware::mach::dev::receive_local()::responses_count==[" << responses_count << ']' << std::endl;
	//std::cout << "noware::mach::dev::receive_local()::responses_nr==[" << responses_nr << ']' << std::endl;
	//for (/*noware::nr::natural n*/responses_count = 0; responses_count < /*zlist_size (peers)*/ noware::nr (node.size (group)); ++responses_count)
	//for (/*noware::nr::natural n*/responses_nr = 0; responses_nr < /*zlist_size (peers)*/ node.size (group); ++responses_nr)
	for (/*noware::nr::natural n*/responses_nr = 0; responses_nr < /*zlist_size (peers)*/ responses_expect; ++responses_nr)
	{
		//std::cout << "noware::mach::dev::receive_local()::while::responses_count==[" << responses_count << ']' << std::endl;
		std::cout << "noware::mach::dev::receive_local()::while::responses_count==[" << responses_nr << ']' << std::endl;
		
		//zmq::message_t message_filter;
		//zmq::message_t message_content;
		
		//std::cout << "noware::mach::dev::receive_local()::loop::receiving::filter" << std::endl;
		//receiver.recv (&message_filter);
		//std::cout << "noware::mach::dev::receive_local()::loop:: received::filter" << std::endl;
		
		std::cout << "noware::mach::dev::receive_local()::loop::receiving::message" << std::endl;
		receiver.recv (&message_content);
		std::cout << "noware::mach::dev::receive_local()::loop:: received::message" << std::endl;
		
		std::cout << "noware::mach::dev::receive_local()::message_tree.deserialize()::pre-call" << std::endl;
		
		//std::cout << "noware::mach::dev::receive_local()::message_filter.data()==[" << static_cast <const char *> (message_filter.data ())	<< ']' << std::endl;
		
		std::cout << "noware::mach::dev::receive_local()::message_content.data()==[" << static_cast <const char *> (message_content.data ()) << ']' << std::endl;
		
		//message = static_cast <const char *> (message_content.data ());
		message = message_content;
		//if (!message_tree.deserialize (static_cast <const char *> (message_content.data ())))
		//{
		//	std::cout << "noware::mach::dev::receive_local()::message_tree.deserialize()==False" << std::endl;
		//	return response;
		//}
		
		std::cout << "noware::mach::dev::receive_local()::message_tree.deserialize()==True" << std::endl;
		// Refresh the list of peers,
		// in case any of them departed the cluster since our previous iteration(s),
		// even if it is improbable.
		/*
		zlist_destroy (&peers);
		//zlist_t * peers;
		peers = zyre_peers (node.zyre ());
		
		if (peers == nullptr)
		{
		  std::cout << "noware::mach::dev::receive_local()::in-while::peers==nullptr" << std::endl;
			return "";
		}
		*/
		// React to/Parse the message.
		// search() returns bool/success if we found the (correct) answer that we are searching for.
		// when we haven't yet found the entire answer, we continue;
		// when we fail, we (could) short-circuit the loop (stop looping).
  	std::cout << "noware::mach::dev::receive_local()::if(search())::pre-call" << std::endl;
		if (search (response, message))
		{
	  	std::cout << "noware::mach::dev::receive_local()::if(search())::break" << std::endl;
			break;
		}
  	std::cout << "noware::mach::dev::receive_local()::if(search())::post-call" << std::endl;
		
		//++n;
	}
  std::cout << "noware::mach::dev::receive_local()::post-loop" << std::endl;
	
	responses_count = responses_nr;
	//zlist_destroy (&peers);
	
  //std::cout << "noware::mach::dev::receive_local()::return response==[" << response << ']' << std::endl;
	return response;
	
	//std::istringstream iss(static_cast<char*>(update.data()));
	//std::cout << "Message=" << '[' << static_cast <char *> (update.data ()) << ']' << std::endl;
}

const bool noware::mach::dev::unicast_local (const zmq::msg & msg, const std::string & request_token) const
//const bool noware::mach::dev::unicast_local (const zmsg_t * msg) const
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
	
//	std::cout << "noware::mach::dev::unicast_local()::msg[content].get_value ().text ()==[" << msg << ']' << std::endl;
	//std::cout << "noware::mach::dev::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	////std::cout << "noware::mach::dev::unicast_local()::msg[content].get_value ().text ()==[" << msg ["content"].get_value ().text () << ']' << std::endl;
	
	//zframe = zmsg_first (msg);
	//message.rebuild (zframe_data (zframe), zframe_size (zframe));
	
	
	std::cout << "noware::mach::dev::unicast_local()::conn==[" << conn << ']' << std::endl;
	
	//msg_serial = msg.serialize ();
	
	zmq::context_t context (1);
	//zmq::socket_t transmitter (context, ZMQ_PUB);
	//zmq::socket_t transmitter (context, ZMQ_PAIR);
	zmq::socket_t transmitter (context, ZMQ_REQ);
	transmitter.connect ("tcp://127.0.0.1:3210");
	//transmitter.connect (conn.c_str ());
	//transmitter.bind ("tcp://*:5555");
	
	
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
	
//	std::cout << "message==" << '[' << static_cast <const char *> (message.data ()) << ']' << std::endl;
	std::cout << "noware::mach::dev::unicast_local()::message==" << '[' << static_cast <const char *> (msg.operator zmq::message_t & ().data ()) << ']' << std::endl;
	
	
  std::cout << "noware::mach::dev::unicast_local()::send()" << std::endl;
	//return
	result =
		//transmitter.send (filter_msg, ZMQ_SNDMORE)
		//&&
		//transmitter.send (msg.operator zmq::message_t & ())
		//transmitter.send (message);
		transmitter.send (msg.operator zmq::message_t & ());
	;
	
	//zclock_sleep (1500);
	
	std::cout << "noware::mach::dev::unicast_local()::send()==[" << (result ? "Success" : "Failure") << ']' << std::endl;
	
	//return true;
	return result;
}

// Short-circuited (triggered by success).
const bool noware::mach::dev::search (zmq::msg &/* result*/, const zmq::msg &/* message*/)// const
{
	std::cout << "noware::mach::dev::search()::called" << std::endl;
	
	return false;
}

const bool noware::mach::dev::search_local (zmq::msg &/* result*/, const zmq::msg &/* message*/)// const
{
	std::cout << "noware::mach::dev::search_local()::called" << std::endl;
	
	return false;
}