<?php include 'header.php' ?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Chat System</title>
	<link  rel ="stylesheet" href = "css/chat.css" type="text/css"/>
    <script src="https://code.jquery.com/jquery-3.6.0.js" integrity="sha256-H+K7U5CnXl1h5ywQfKtSj8PCmoN9aaq30gDh27Xc0jk=" crossorigin="anonymous"></script>
</head>
<body>
	
	<div class="centeralised">
	<div><h2>Chat here...</h2></div>
	<div class="chathistory"></div>
	<div class="chatbox">
		
		<form action="" method="POST">
			
			<textarea class="txtarea" id="message" name="message"></textarea>
		</form>
	</div>
	</div>
	
	<script>
	
		 $(document).ready(function(){
			loadChat();
		});
		
		
		$('#message').keyup(function(e){
		 var message =$(this).val();
		 
		 if( e.which == 13 ){
				$.post('handlers/ajax.php?action=SendMessage&message='+message, function(response){
				loadChat();
                $('#message').val('');				
				
				});
			}
			
			
		});	

     function loadChat()
		{
			$.post('handlers/ajax.php?action=getChat', function(response){
				
				$('.chathistory').html(response);
			});
		}
		
		setInterval(function(){
			
			loadChat();
		},1000);
		
	</script>
</body>
</html>


















































































