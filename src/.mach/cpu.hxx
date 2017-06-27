#pragma once

//namespace noware
//{
	//namespace machine
	//{
		// processor cpu
		// thread task job
		class cpu
			: public dev
		{
			public:
				// operator operation
				enum class opr
				{
					none,
					// For controlling the flow of the execution:
					//and,	// and intersection
					//or, // or union
					
					get,				// attainment obtainment get read
					set,				// assignment settlement set write
					exist,			// presence existence
					rm,					// removal resettal rm
					
					add,				// addition
					substr,			// substraction
					multi,			// multiplication
					div,				// division
					
					exp,				//exponentiation
					modulo,			// remainder of division
					modulus,		// absolute value
					complement,	// complement compl
					
					cat					// concatenation cat
					
					// Control of the flow
					//eql,
					//grtr,
					//grtr_eql,
					//lowr,
					//lowr_eql,
					//output		// output set echo
					//go,			// go[[ ]to] skip jump hop
				};
				
				class instr
					: public noware::serial
				{
					public:
						instr (void);
						instr (const std::string &);
						virtual ~instr (void);
						
						opr oprn;	// Optional.
						
						// operand
						//noware::var operand1;
						//noware::var operand2;	// Optional.
						noware::var oprnd [2];
						
						//dependents;	// Not really needed.
						//dependencies;
						
						// evaluate value val
						//const bool operator== (const instruction &/* other*/) const;
						virtual const noware::var /*e*/val/*uate*/ (void) const;
						
						
						friend class boost::serialization::access;
						
						template <typename archive>
						void serialize (archive &, const unsigned int &/* version*/);
					public:
						// TODO
						// 
						// inherit these two functions
						// from noware::serial
						// (do not redeclare)
						virtual const std::string serialize (void) const;
						virtual const bool deserialize (const std::string &/* serial*/);
				};
				
				cpu (void);
				virtual ~cpu (void);
				
				static const std::string grp_dft;
				
				// Queue
			public:
			//protected:
				// dequeue beginning first head top pop next fetch operate
				virtual const instr next (void) const;
				virtual const bool dequeue (void);
				//const instruction dequeue (void);
			public:
				virtual const noware::nr size (void) const;
				virtual const bool empty (void) const;
				virtual const bool full (void) const;
				
				virtual const bool enqueue (const instr &);
				//const bool enqueue (const operation &/* operator*/, const noware::var &/* operand1*/, const noware::var &/* operand2*/ = "");	// Accurate.
				virtual const bool enqueue (const noware::var &/* operand1*/, const opr &/* operator*/ = opr::none, const noware::var &/* operand2*/ = "");	// Convenient.
				// do perform execute apply evaluate
				//const bool apply (const instruction &);
				
				// Store
			public:
				const bool exist (const std::string &/* key*/) const;
				const bool exist (const std::string &/* group*/, const std::string &/* key*/) const;
				
				const bool remove (const std::string &/* group*/, const std::string &/* key*/);
				const bool remove (const std::string &/* key*/);
				
				const std::string/* value*/ get (const std::string &/* group*/, const std::string &/* key*/) const;
				const std::string/* value*/ get (const std::string &/* key*/) const;
				
				const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/);
				const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/);
			protected:
				virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/);
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				//virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				//virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
			protected:
				// Process/Find/Search for/ the next instruction on-the-fly.
				// Do not store an instruction queue.
				//std::queue <instruction> queue;
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
*/
