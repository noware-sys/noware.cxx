class container
{
	public:
		//enum class type
		enum type
		{
			generic,
			numeric
			
			//text
			//string
			//number,
		};
		
		container (void);
		/*
		container (const container &);
		container (const bool &);
		container (const text &);
		container (const std::string &);
		container (const math::nr &);
		
		const container & operator = (const container &);
		const container & operator = (const bool &);
		const container & operator = (const text &);
		const container & operator = (const std::string &);
		const container & operator = (const math::nr &);
		*/
		const std::string serialize (void) const;
		const bool deserialize (const std::string &/* serial*/);
	//protected:
		friend class boost::serialization::access;
		
		// The type of the variable currently being stored.
		// Only one type is active anytime.
		type t;
		
		//noware::text text;
		std::string text;
		//noware::math::numbers::real number;
		nr number;
		//boost::any content;
		
		template <typename archive>
		void serialize (archive &/* archive*/, const unsigned int &/* version*/);
};

