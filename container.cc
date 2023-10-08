class int_container{
    public:
        int_container(int const* data_in, nsigned len_in)
        {
            data =new(std::nothrow)int[len_in];
            len=data==0?0:len_in;
            for(unsigned n=0; n<len; ++n)
                data[n] = data_in[n];
        }

        ~int_container(){
            delete[]data;
        }

        
}