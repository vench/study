
// Hint's
function CreateElement(name, attributes, parent) {
    var el = document.createElement(name);
    for(var key in attributes) {
        if(key === 'text') {
            el.innerText = attributes[key];
        } else {
            el.setAttribute(key, attributes[key]);
        }        
    }
    if(parent) {
        parent.appendChild(el)
    }
    return el;
}

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
}

// class 
var HistoryGame = {
    Data:{},
    SetState: function(stateGame, typeWin){

    },
    GetByState: function(stateGame){

    }
};




// class Player
function Player(type) {
    this.type = type || 0;
}

Player.prototype.GetType = function() {
    return this.type;
}

// class StateCeil
function StateCeil(type) {
    this.type = type || 0;
    this.color = undefined;
};

StateCeil.prototype.Draw = function(ctx, x, y, w, h) {
    if( this.type == 0) {
        return;
    } 

   var lineWidth =  ctx.lineWidth;
   var strokeStyle = ctx.strokeStyle; 
   if(!!this.color) {
    ctx.strokeStyle = this.color;
   }
   ctx.lineWidth = 3;
   if(this.type == 2) {
        ctx.beginPath();   
        ctx.arc(x * w + w/2, y * h + h/2, h/3, 0, 2 * Math.PI);
        ctx.stroke();

   } else {
        ctx.beginPath();  
        ctx.moveTo(x * w + w/4, y * h + h/4);
        ctx.lineTo(x * w + w-w/4, y * h + h-h/4);

        ctx.moveTo(x * w + w-w/4, y * h +h/4);
        ctx.lineTo(x * w + w/4, y * h + h-h/4);
        ctx.stroke();    
   }
   ctx.lineWidth = lineWidth;
   ctx.strokeStyle = strokeStyle;
};

//
StateCeil.prototype.SetType = function(type) {
    if(this.IsEmpty()) {
        this.type = type;
        return true;
    }
    return false;   
};

StateCeil.prototype.IsEmpty = function() {
    return this.type === 0;
}


// class StateGame
function StateGame(ceilSize) {
    this.positions = [
        new StateCeil(0),
        new StateCeil(0),
        new StateCeil(0), 
        new StateCeil(0),
        new StateCeil(0),
        new StateCeil(0), 
        new StateCeil(0),
        new StateCeil(0),
        new StateCeil(0)];
    this.ceilSize = ceilSize || 100;    
};

StateGame.prototype.GetState = function(x,y) {
    var ix = Math.floor(x / this.ceilSize),
        iy = Math.floor(y / this.ceilSize),
        index = ix + iy * 3;
    ;
    return this.positions[index] ? this.positions[index] : null;
};

StateGame.prototype.Draw = function(ctx) {
    for(var i = 0; i < 3; i ++) {
        for(var j = 0; j < 3; j ++) {
            var index = i + j * 3; 
            this.positions[index].Draw(ctx, i, j, this.ceilSize, this.ceilSize);
        }
    }
};

// class GAME 
function Game(parent) {
    parent = document.body || parent;

    this.grid = {
        width: 300, height: 300
    };
    CreateElement('h1', {
        'text': 'Крестики нолики', 
    }, parent);
    var btnNewGame = CreateElement('button', {'text':'Новая игра'}, CreateElement('div', {}, parent)); 
    btnNewGame.addEventListener('click', this.NewGame.bind(this));

    this.canvas = CreateElement('canvas', {
        'id': 'canvasdummy', 'width': this.grid.width, 'height': this.grid.height, 
    }, parent); 

    this.canvas.addEventListener('click', this.OnHandlerClickCanvas.bind(this), false);
    
    this.log = CreateElement('div', {}, parent);

    this.player1 = new Player(1);
    this.player2 = new Player(2);
   
    this.state = new StateGame();
}

Game.prototype.Info = function(text) {
    this.log.innerHTML = text;
};

//
Game.prototype.OnHandlerClickCanvas = function(e){
    var x, y, target = e.srcElement || e.target;
    if (e.pageX || e.pageY) { 
        x = e.pageX;
        y = e.pageY;
    }  else { 
        x = e.clientX + document.body.scrollLeft + document.documentElement.scrollLeft; 
        y = e.clientY + document.body.scrollTop + document.documentElement.scrollTop; 
    } 
    x -= target.offsetLeft;
    y -= target.offsetTop; 

    var cell = this.state.GetState(x, y);
    this.Player1Move(cell);
};

Game.prototype.Player1Move = function(posCeil){
    if(this.CheckGameOver()) {
        return this.GameOver();
    }
    if(posCeil && posCeil.SetType(this.player1.GetType())) { 
        this.Draw();
        if(this.CheckGameOver()) {
            return this.GameOver();
        }

        this.Player2Move();
        this.Draw();
        if(this.CheckGameOver()) {
            return this.GameOver();
        }
        
    } else {
        this.Info("Ход недоступен");
    }
}

//
Game.prototype.Player2Move = function(){
    var availables = [];
    for(var i = 0;i < this.state.positions.length; i ++ ) {
        if(this.state.positions[i].IsEmpty()) {
            availables.push(i);
        }
    }
   
    if(availables.length == 0) {
        return;
    }

    var index = getRandomInt(0, availables.length);
    this.state.positions[availables[index]].SetType(this.player2.GetType());
}

Game.prototype.CheckGameOver = function() {
    var p = this.state.positions,
        colorWin = '#f00'
    ;
     
    for(var i = 0; i < 3; i ++) {
        if(p[i*3].type == p[i*3+1].type && 
            p[i*3+1].type == p[i*3+2].type && p[i*3].type != 0) {
                p[i*3+0].color = p[i*3+1].color = p[i*3+2].color = colorWin;
                this.typeWin = p[i*3].type;
                return true;
        }
        if(p[i].type == p[3+i].type && 
            p[3+i].type == p[6+i].type && p[i+3].type != 0) {
                p[i+3].color = p[i+6].color = p[i].color = colorWin;
                this.typeWin = p[i+3].type;
                return true;
        }
    }

    if(p[0].type == p[4].type && p[4].type == p[8].type && p[0].type != 0) {
        p[0].color = p[8].color = p[4].color = colorWin;
        this.typeWin = p[0].type;
        return true;
    }
    if(p[2].type == p[4].type && p[4].type == p[6].type && p[2].type != 0) {
        p[6].color = p[2].color = p[4].color = colorWin;
        this.typeWin = p[2].type;
        return true;
    }
    
    return false;
};    

Game.prototype.NewGame = function() {
    this.state = new StateGame();
    this.Init();
}    

Game.prototype.GameOver = function() {
    this.Draw();
    this.Info("Игра закончена!!!" + "\nПобеда: " + 
     (this.typeWin == 1 ? 'X' : 'O') + '!!!');
     HistoryGame.SetState(this.state, this.typeWin);
};

//
Game.prototype.Draw = function() {
 
    var ctx = this.canvas.getContext("2d");
    ctx.clearRect(0, 0, this.grid.width, this.grid.height);
     
    var len = 3,
        ws = Math.floor(this.grid.width / len),
        hs = Math.floor(this.grid.height / len);
    for(var i = 1; i < len; i ++) {
        ctx.beginPath();
        ctx.moveTo(ws*i, 0);
        ctx.lineTo(ws*i , this.grid.height); 
        ctx.stroke();
        ctx.beginPath();
        ctx.moveTo(0, hs*i);
        ctx.lineTo(this.grid.width , hs*i); 
        ctx.stroke()
    }

    this.state.Draw(ctx);
    
};

Game.prototype.Init = function() {
    this.typeWin = -1;
    this.Draw();
};


window.onload = function() {
    var game = new Game();
    game.Init();
}; 

