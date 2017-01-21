#include <iostream>
 int main()
 {
     //Задача А2 
	 char y,z;
	 int y1,z1;
	 short int x,v;
	 std::cout<<"Enter x,y,z"<<std::endl;
	 std::cin>>x;
	 scanf("%d%d",&y1,&z1);
	 y=y1;
	 z=z1;
	 //Реализация на си:
	 v=((x+2)*(y-3)-2)/(z-5)+2;
	 std::cout<<"v="<<v<<std::endl;

	 //Реализация на ассемблере:
	
	 _asm{
		 MOVSX EAX, x
		 ADD EAX, 2

		 MOVSX ECX, y
		 SUB ECX, 3

		 IMUL EAX, ECX

		 SUB EAX, 2

		 MOVSX ECX, z
		 SUB ECX, 5

		 CDQ

		 IDIV ECX

		 ADD EAX, 2

		 MOV v, AX
	 }
	 
	 std::cout<<"v="<<v<<std::endl;

	 //Задача А3
	 int *arr=new int[4];
	 for (int i=0;i<4;++i)
	 {
		 std::cin>>arr[i];
	 }
	 std::cout<<std::endl;
    //Реализация на си:
	/* if(arr[0]==arr[3] && arr[2]!=a[0])
	 {
		 arr[1]+=2;
	 }
	 else
	 {
		 int temp=arr[0];
		 arr[0]=a[1];
		 arr[1]=temp;
	 }*/
    //Реализация на ассемблере:
	 _asm{
		 mov ebx,arr
		 mov eax,dword ptr[ebx]
		 mov ecx, dword ptr[ebx+12]
		 cmp eax, ecx
		 jne L2
		 mov ecx,dword ptr[ebx+8]
		 cmp eax,ecx
		 je L2
		 ADD dword ptr [ebx+4],2
		 jmp L1

		L2: 
		mov edx, dword ptr [ebx+4]
		mov dword ptr [ebx], edx
		mov dword ptr [ebx+4], eax
		L1:

	 }
	for (int i=0;i<4;++i)
	 {
		 std::cout<<arr[i]<<std::endl;;
	 }
	 delete arr;

	 return 0;
 }