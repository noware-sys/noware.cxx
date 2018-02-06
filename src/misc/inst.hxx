namespace noware
{
	namespace misc
	{
		class inst
		{
			public:
				instance (void);
				virtual ~instance (void);
				
				virtual const unsigned int id (void) const;
				//virtual static const unsigned int count (void) const;
				virtual const unsigned int nr (void) const;
			protected:
				//static unsigned int count;
				//static noware::db::sqlite ids;
				noware::db::sqlite ids;
				unsigned int _id;	// _id local this self current
		};
	}
}
