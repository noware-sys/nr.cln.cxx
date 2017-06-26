//#pragma once

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
				enum class operation
				{
					none,
					// For controlling the flow of the execution:
					// and intersection
					// or union
					
					obtainment,	// attainment obtainment get read
					assignment,	// assignment settlement set write
					//presence,
					removal,		// removal resettal
					
					addition,
					substraction,
					multiplication,
					division,
					
					exponentiation
					modulo,
					modulus,
					complement,
					
					//cat,				// concatenate
					
					//output		// output set echo
					//go,			// go[[ ]to] skip jump hop
				};
				
				class instruction
				{
					public:
						instruction (void);
						~instruction (void);
						
						operation operation;	// Optional.
						//noware::var operand1;
						//noware::var operand2;	// Optional.
						noware::var operand [2];
						
						//dependents;	// Not really needed.
						//dependencies;
						
						//const bool operator== (const instruction &/* other*/) const;
						const noware::var /*e*/val/*uate*/ (void) const;
				};
				
				cpu (void);
				~cpu (void);
			protected:
				// dequeue beginning first head top pop next fetch operate
				const instruction next (void) const;
				const bool dequeue (void);
				//const instruction dequeue (void);
			public:
				const bool enqueue (const instruction &);
				//const bool enqueue (const operation &/* operator*/, const noware::var &/* operand1*/, const noware::var &/* operand2*/ = "");	// Accurate.
				const bool enqueue (const noware::var &/* operand1*/, const operation &/* operator*/ = operation::none, const noware::var &/* operand2*/ = "");	// Convenient.
				// do perform execute apply evaluate
				//const bool apply (const instruction &);
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
