#pragma once

//namespace noware
//{
	//namespace machine
	//{
		class queue
			: public dev
		{
			public:
				queue (void);
				virtual ~queue (void);
				
				static const std::string grp_dft;
				
				// dequeue beginning first head top pop next current present fetch operate
				virtual const std::string next (void) const;
				// get the next element and dequeue
				virtual const std::string next_dequeue (void);
				virtual const bool dequeue (void);
				virtual const bool enqueue (const std::string &/* element*/);
				virtual const noware::nr size (void) const;
				virtual const bool empty (void) const;
				virtual const bool empty_local (void) const;
				virtual const bool full (void) const;
				virtual const bool full_local (void) const;
				
			protected:
				virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/, zmq::msg &/* response*/);
				virtual const bool/* success*/ respond_post (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/, const zmq::msg &/* response; read-only*/);
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
				
			protected:
				std::queue <std::string> queue;
		};
	//}
//}

/*
	{
		(ins(req()));
		(ins(req()));
		(ins(req()));
	}
*/

/*
	activity
	{
		process (exp (ins));
		process (exp (ins));
		process (exp (ins));
	}
*/

/*
	activity
	{
		process (operation (instruction ...) ...);
		process (operation (instruction ...) ...);
		process (operation (instruction ...) ...);
	}
*/

/*
	main activity
	# parallel
	{
		sub activity / action ...
		# parallel
		{
			process
			# serial
			{
				operation ...
				# parallel or serial
				{
					instruction; ...
				}
			}
		}
	}
*/

/*
	
	{
		# parallel
		{
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
			
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
			
			process
			{
				# serial
				{
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
					
					operation
					{
						# serial
						{
							instruction;
							instruction;
							instruction;
						};
					};
				};
			};
		};
	};
*/
