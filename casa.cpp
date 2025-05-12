    botaoSim.setFillColor(sf::Color::Green);
    botaoSim.setPosition(200, 200);

    sf::Text textoSim("Sim", font, 24);
    textoSim.setFillColor(sf::Color::Black);
    textoSim.setPosition(235, 210);

    sf::RectangleShape botaoNao(sf::Vector2f(150, 50));
    botaoNao.setFillColor(sf::Color::Red);
    botaoNao.setPosition(450, 200);

    sf::Text textoNao("Não", font, 24);
    textoNao.setFillColor(sf::Color::Black);
    textoNao.setPosition(485, 210);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (isMouseOver(botaoSim, window)) {
                        mensagem.setString("Sabia que diria sim! ❤️");
                    }
                }
            }
        }

        // Faz o botão "Não" fugir do mouse
        if (isMouseOver(botaoNao, window)) {
            float newX = static_cast<float>(std::rand() % (window.getSize().x - static_cast<int>(botaoNao.getSize().x)));
            float newY = static_cast<float>(std::rand() % (window.getSize().y - static_cast<int>(botaoNao.getSize().y)));
            botaoNao.setPosition(newX, newY);
            textoNao.setPosition(newX + 35, newY + 10);
        }

        window.clear(sf::Color::Blue);
        window.draw(pergunta);
        window.draw(botaoSim);
        window.draw(textoSim);
        window.draw(botaoNao);
        window.draw(textoNao);
        window.draw(mensagem);
        window.display();
    }

    return 0;
}
