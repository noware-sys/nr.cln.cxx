//#pragma once

//#include "../var.hdr.cxx"

//namespace noware
//{
	// Place in another project (kernel/os)?
	//namespace machine
	//{
			class device //: misc::instance
			{
				public:
					device (void);
					virtual ~device (void);
					
					virtual const noware::any evaluate (const any &/* expression*/);
				//protected:
					//static net::cluster nodes;
					net::node node;
			};
	//}
//}
