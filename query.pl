
sub loop{

use Scalar::Util qw(looks_like_number);
@1 = ("clique" , "size");
@2 = ("length", "shortest", "path", "between", "two","least");
@3 = ("list", "people", "shortest", "path", "between", "two","name","person");
@4 = ("shortest", "path", "graph", "between","all","pair");
@5 = ("importance");
@6 = ("more", "important", "than");

%dictionary = (
			1 => "@1",
			2 => "@2",
			3 => "@3",
			4 => "@4",
			5 => "@5",
			6 => "@6"
);



print "Enter Your Query:","\n";
$take= <>;
@question = split(/ /,$take);

#@question = ("shortest","size" ,"2748742" , "IITD","IITM" , "34767467");

for($i = 0; $i <=$#question; $i++)
{
	$question[$i] = lc($question[$i]);      ###converting all  question words to lowercase
}

for($i = 0; $i <=$#question; $i++)
{
	 # print $question[$i],"\n";
}

%count = ( "1" => 0, "2" => 0, "3" => 0, "4" => 0, "5" => 0, "6" => 0);

@temp = ("12345\n");

#for($i = 0; $i <= $#question; $i++)
#{
#	print $question[$i],"\n" ;
#	print "bye\n\n\n" ;
#	for($j = 1; $j <=6 ; $j++)
#	{
#		@temp = split(/ /, $dictionary{$j});      ###the words appear concatenated as a single
#									###		sentence. Splitting it into its component words.
#print @temp,"\n";
#
#		for($k = 0; $k <= $#temp; $k++)
#		{
#			print $temp[$k],"\n";
#			print $question[$i],"\n\n";
#			
#			if( $question[$i] eq $temp[$k] )
#			{
#				
#				$count{$j}++;
#				
#			}
#		}
#	}
#}


for($i = 0; $i <= $#question; $i++)
{
	if( $question[$i] eq "clique" )
			{
				$count{1}=$count{1}+5 ;
				
	
				
			}
			elsif( $question[$i] eq "list" )
			{
				
				$count{3}=$count{3}+2 ;
					
	
				
			}
			elsif( $question[$i] eq "length" )
			{
				
				$count{2}=$count{2}+2 ;
					
				
			}
			elsif( $question[$i] eq "importance" )
			{
				
				$count{5}=$count{5}+2 ;
					
	
			}
			elsif( $question[$i] eq "important" )
			{
				
				$count{6}=$count{6}+2 ;
					
				
			}
	
	for($j = 1; $j <=6 ; $j++)
	{
		@temp = split(/ /, $dictionary{$j});      ###the words appear concatenated as a single
									###		sentence. Splitting it into its component words.

		for($k = 0; $k <= $#temp; $k++)
		{
			if( $question[$i] eq $temp[$k] && $question[$i] ne "clique"  && $question[$i] ne "list"  && $question[$i] ne "length"  && $question[$i] ne "importance"  && $question[$i] ne "important" )
			{
				
				$count{$j}++;
				
			}
		}
	}
}




$max = -1;
$maxkey = 0;

for($i =1; $i<=6; $i ++)		## finding the maximum key
{
	 # print "$i   =>    $count{$i}   matches\n";
	if($count{$i}>$max)
	{
		$max = $count{$i};
		$maxkey = $i;
	}
}

$files = "cache.temp";
unlink ($files);
open (OUTFILE, ">>$files");
print OUTFILE "0";
close (OUTFILE);
#@universities =(); 
@id =(); 
#
#for($i = 0; $i <=$#lines; $i++)
#{
#	$lines[$i] = lc($lines[$i]);      ###converting all  question words to lowercase
#}
#for($i=0;$i <= $#lines;$i++){  
#	
#	for($j=0; $j<= $#question; $j++){
#		$s1 =$question[$j]."\n"  ;
#		$s2 =$lines[$i]  ;
#		if(($s1 eq $s2)==1){
#			push(@universities,$question[$j]) ;
#		}
#	}
#}
$correct_id =0 ;
	$check = "" ;
	for($i=0; $i< length($take); $i++){
		$imp = substr $take, $i, 1 ;
		# print $imp,"\n" ;
		if(looks_like_number($imp)){
			# print "in looks like number","\n" ;
			$check = $check.$imp ;
			$correct_id =1 ;
			# print $check,"\n" ;

		}
		elsif($correct_id ==1 && !looks_like_number($imp)){
			# print "in verified id loop\n",$imp,"\n" ;
			push(@id,$check) ;
			$check = "" ;
			$correct_id =0 ;
		}
		elsif($correct_id ==1 && $i == length($take)){
			# print "in verified id loop\n",$imp,"\n" ;
			push(@id,$check) ;
			$correct_id =0 ;
		}

	}
# print "The question number is $maxkey\n " ;


my $prog = "./analyzer"; #### Address of c++ executable ;

if (-f $prog)   # does it exist?
{
 
if ($#id >0){

 	system($prog,$maxkey,$id[0],$id[1]);
 }
 elsif($#id ==0){
 	system($prog,$maxkey,$id[0]);
 }
 }
else  
{
    print "$prog doesn't exist.\n";
}

 

}

while (0<1) {
	&loop();
}