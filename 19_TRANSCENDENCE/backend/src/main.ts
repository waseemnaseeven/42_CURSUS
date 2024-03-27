import { NestFactory } from '@nestjs/core';
import { AppModule } from './app.module';
import { ValidationPipe } from '@nestjs/common';
import config from './utils/config';
import { DocumentBuilder, SwaggerModule } from '@nestjs/swagger';
import cookieParser from 'cookie-parser';
import { IoAdapter } from '@nestjs/platform-socket.io';

async function bootstrap() {
  const app = await NestFactory.create(AppModule);

  app.useWebSocketAdapter(new IoAdapter(app));
  const builder = new DocumentBuilder()
    .setTitle('Transcendence API')
    .setDescription('Transcendence API description')
    .setVersion('0.1')
    .build();

  const document = SwaggerModule.createDocument(app, builder);
  SwaggerModule.setup('api', app, document);

  app.enableCors({
    origin: `http://localhost:${config.FRONTEND_PORT}`,
    credentials: true,
    methods: ['GET', 'POST', 'PUT', 'DELETE', 'PATCH'],
    allowedHeaders: ['Content-Type', 'Authorization'],
  });

  app.useGlobalPipes(
    new ValidationPipe({
      transform: true,
      whitelist: true,
    }),
  );

  app.use(cookieParser());

  await app.listen(Number(config.BACKEND_PORT));

  console.log('');
}

bootstrap();
